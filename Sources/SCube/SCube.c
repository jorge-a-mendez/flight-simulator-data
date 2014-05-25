/*###############################################################################
 * SCube.c
 *		This module contains the functions used to acquire the data from 
 *		capacitive sensor to locate position in a 3D space. It measures
 *		the time of charge and discharge controlling the state of a simple
 *		digital input/output pin.
 *		Authors:
 *			Rafael Rodriguez (rafaelrs307@gmail.com)
 *			Jorge Mendez (jorgeamendezm@gmail.com)
 *
 *###############################################################################*/



#include "SCube/SCube.h"
#include "Comm/SerialComm.h"
#include "Events.h"

//Constants

#define 	CH_X			0u			//< Identifier for the plates. Each one corresponding to an axis.						
#define 	CH_Y			1u
#define 	CH_Z			2u

#define 	RESOLUTION		8			//< Resolution for the measurement.
#define 	TOTAL			17			//< Number of samples needed to take 2 cycles of a 60Hz signal.

#define 	__Enter_Critical		asm {SEI};			
#define 	__Exit_Critical			asm {CLI};

#define 	INPUT			0			//< Digital pins direction.
#define 	OUTPUT			1




typedef struct{
	int32u count[3];				//< Time of the charge and discharge cycles.	
	int32u total;					//< Total cycles measured.
}__SCube_data;

/*
 * 	De los datos medidos en el programa de Testing. Se demostro que solo 
 * 	es necesario enteros de 16bits, sin embargo, este proyecto puede ser
 * 	diferente. TOMAR EN CUENTA COMO POSIBLE BUG.
 */


typedef union{						//< Union to facilitate the transmission.			
	int16u period;
	int8u byte[2];
}__period;



// Global Variables.
__SCube_data buf;					//< Buffer of the Plates Data.
bool datalista;						//< Boolean to indicate when the data's ready.

// Private functions.

void reset();


//##################################################################################

// Public Functions.

//##################################################################################

void init_SCube(){
	buf.count[0] = 0;
	buf.count[1] = 0;
	buf.count[2] = 0;
	buf.total = 0;
	datalista = false;
}

bool Scube_data_lista() {
	return datalista;
}

void read_SCube(){
	
	if (datalista) return;
	
	__Enter_Critical
	
		ControlX_SetDir(OUTPUT);		//< Output.
		ControlX_ClrVal();				//< Discharge the plate
		for (j = 0; j < 50; j++);		//< Delay
		ControlX_SetDir(INPUT);			//< Set the pin to an input
		while (!ControlX_GetVal())
			count[CH_X]++;				//< Add time to the count
	__Exit_Critical

	__Enter_Critical
		
		ControlY_SetDir(OUTPUT);		//< Output.
		ControlY_ClrVal();				//< Discharge the plate
		for (j = 0; j < 50; j++);		//< Delay
		ControlY_SetDir(INPUT);			//< Set the pin to an input
		while (!ControlY_GetVal())
			count[CH_Y]++;				//< Add time to the count
	__Exit_Critical

	
	__Enter_Critical
		
		ControlZ_SetDir(OUTPUT);		//< Output.
		ControlZ_ClrVal();				//< Discharge the plate
		for (j = 0; j < 50; j++);		//< Delay
		ControlZ_SetDir(INPUT);			//< Set the pin to an input
		while (!ControlZ_GetVal())
			count[CH_Z]++;				//< Add time to the count
	__Exit_Critical
	buf.total++;
	if (buf.total == TOTAL) {
		datalista = true;
	}
}

void send_SCube(){
	int8u correccion = 0, i;
	_trama t;
	__period period;
	t.t[0] = panel;
	t.tam = 4;
	if (!datalista) return;
	
	// Send the data of every plate.
	
	for(i = 0; i < 2; i++){ 
		period.period = (buf.count[i] << RESOLUTION) / buf.total;
		if(period.byte[0] != 0xFF) 
			t.t[1] = period.byte[0];
		else{ 
			correccion |= 0x02;
			t.t[1] = 0xFE;
		}
		if(period.byte[0] != 0xFF) 
			t.t[2] = period.byte[0];
		else{
			correccion |= 0x01;
			t.t[2] = 0xFE;
		}
		t.t[3] = correccion;
		send_data(&t,correccion);
	}
	
	reset();
}

// ##################################################################################

//		Private functions implementation.

// ##################################################################################
void reset() {
	init_SCube();
}

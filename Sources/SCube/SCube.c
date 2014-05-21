/*
 * SCube.c
 *
 */


#include "SCube/SCube.h"
#include "Comm/SerialComm.h"
#include "Events.h"

//Constantes

#define CH_X			0u						
#define CH_Y			1u
#define CH_Z			2u
#define RESOLUTION		8
#define TOTAL			17		//< Numero de muestras para dos periodos de 60Hz. (1/30)s / 2ms
#define __Enter_Critical		asm {SEI}			//< REVISAR ESTA INSTRUCCION
#define __Exit_Critical			asm {CLI}
#define INPUT			0
#define OUTPUT			1
typedef struct{
	int32u count[3];				//< Tiempo de cargas y descargas.	
	int32u total;				//< Total de ciclos medidos.
}__SCube_data;

/*
 * 	De los datos medidos en el programa de Testing. Se demostro que solo 
 * 	es necesario enteros de 16bits, sin embargo, este proyecto puede ser
 * 	diferente. TOMAR EN CUENTA COMO POSIBLE BUG.
 */

typedef union{				
	int16u period;
	int8u byte[2];
}__period;

__SCube_data buf;
bool datalista;

void reset();


///#################################################################################
// Funciones publicas.


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
	if (total != TOTAL) return;
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

// Funciones privadas

void reset() {
	init_SCube();
}

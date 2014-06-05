/*
 * Piezo.c
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */

#include "Piezo/Piezo.h"
#include "Comm/SerialComm.h"
#include "Events.h"


//Constantes.

#define NOSHOT			0u			//< Shot intensities depending of pressured applied to piezoelectric sensor
#define SOFT			1u
#define MEDIUM			2u
#define HARD			3u



extern piezo_data buff;		//< global variable from Events.c

void __reset_piezo();
bool datalista;


//########################################################################################

// Public Functions.

//########################################################################################

/* #######################################################################################
 * 		Function: init_piezo. Initialize piezo values.
 * 		Parameters:
 * 			
 * 		Return:
 * 			
 * ######################################################################################## */

void init_piezo(){
	buff.shot_val = NOSHOT;
	buff.cmp1 = false;
	buff.cmp2 = false;
	buff.cmp3 = false;
	datalista = false;
}


/* ########################################################################################
 * 		Function: piezo_data_lista. Verify if there has been a new shot.
 * 		Parameters:
 * 			
 * 		Return:
 * 			bool datalista. 
 * 				- true: one new shot.
 * 				- false: no new shots.
 * ######################################################################################## */

bool piezo_data_lista(){
	return datalista;
}


/* ########################################################################################
 * 		Function: get_shot. Check the intensity of the shot.
 * 		Parameters:
 * 			
 * 		Return:
 * 		
 * 		Description: 	Interruptions occur when piezoelectric sensor reaches values of 
 * 						0.5V, 1.5V and 2.5V, setting comparator values to true. Another
 * 						interrupt occurs when voltage goes back to 0V, calling this
 * 						function. It checks the value of comparators and decides what the
 * 						intensity of the shot was. Datalista is set to true.
 * 						
 * ######################################################################################## */

void get_shot(){
	datalista = true;
	if(buff.cmp3){			//< Revisar el comparador 3 (2,5V)	
		buff.shot_val = HARD;
	}
	else if (buff.cmp2){		//< Revisar el comparador 2 (1,5V)
		buff.shot_val = MEDIUM;
	}
	else if(buff.cmp1){		//< Revisar el comparador 1 (0,5V)
		buff.shot_val = SOFT;
	}
	else {
		buff.shot_val = NOSHOT;
		datalista = false;
	}
}


/* ########################################################################################
 * 		Function: send_shot. Queues the last shot value in the transmit queue.
 * 		Parameters:
 * 			
 * 		Return:
 * 			
 * ######################################################################################## */

void send_shot(){
	int8u correction = 0;
	_trama t;
	if (!datalista)
		return;
	t.t[0] = PIEZO;
	t.t[1] = buff.shot_val;
	t.tam = 2;	
	send_data(&t, correction);
	__reset_piezo();
	
}
// ##################################################################################

//		Private functions implementation.

// ##################################################################################

// Every time a shot is fired, all piezo attributes are reset.

void __reset_piezo(){
	init_piezo();
}


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

#define NOSHOT			0u
#define SOFT			1u
#define MEDIUM			2u
#define HARD			3u



extern piezo_data buff;

void __reset_piezo();

///#################################################################################
// Funciones publicas.

void init_piezo(){
	buff.shot_val = NOSHOT;
	buff.cmp1 = false;
	buff.cmp2 = false;
	buff.cmp3 = false;
}

//Los comparadores en estado estable estan en 1. Si hay un disparo, se colocan en cero y 
//el comparador 1 (0,5V) genera una interrupcion. La interrupcion llema a get_shot().

void get_shot(){
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
	}
}

void send_shot(){
	int8u correction = 0;
	_trama t;
	if (buff.shot_val != NOSHOT){
		t.t[0] = PIEZO;
		t.t[1] = buff.shot_val;
		t.tam = 2;	
		send_data(&t, correction);
		__reset_piezo();
	}
}

///#################################################################################
// Funciones privadas


void __reset_piezo(){
	init_piezo();
}


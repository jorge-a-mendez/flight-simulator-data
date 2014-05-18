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

typedef struct{
	int8u piezo;									//< Valor de la se;al del piezoelectrico.
	int8u shotVals[PIEZO_BUFSIZE];					//< Valores de disparos anteriores
	int8u last;										//< Ultimo elemento en la cola.
	int8u prevVal;									//< Valor anterior leido del ADC.
	int8u status;									//< Subida o bajada.
}__piezo_data;

__piezo_data bff;

int8u shot_val;

///#################################################################################
// Funciones publicas.

void init_piezo(){
	shot_val = NOSHOT;
}

//Los comparadores en estado estable estan en 1. Si hay un disparo, se colocan en cero y 
//el comparador 1 (0,5V) genera una interrupcion. La interrupcion llema a get_shot().
void get_shot(){
	if(!CMP3_GetVal()){			//< Revisar el comparador 3 (2,5V)	
		shot_val = HARD;
	}
	else if (!CMP2_GetVal()){	//< Revisar el comparador 2 (1,5V)
		shot_val = MEDIUM;
	}
	else if(!CMP1_GetVal()){	//< Revisar el comparador 1 (0,5V)
		shot_val = SOFT;
	}
	else {
		shot_val = NOSHOT;
	}
}

void send_shot(){
	int8u correction = 0;
	_trama t;
	t.t[0] = PIEZO;
	t.t[1] = shot_val;
	t.tam = 2;
	if (t.t[1] != NOSHOT){
		send_data(&t, correction);
		shot_val = NOSHOT;
	}
}

///#################################################################################
// Funciones privadas



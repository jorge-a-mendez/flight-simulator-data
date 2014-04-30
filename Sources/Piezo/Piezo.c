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
#define MAXVALUE		255
#define CH_PIEZO		4u
#define CH_DETECT		5u
#define PIEZO_BUFSIZE	32u	



typedef struct{
	int8u detector;
	int8u piezo;
	int8u shotVals[PIEZO_BUFSIZE];
	int8u last;
}__piezo_data;

__piezo_data bff;

int8u __get_shotVal();


///#################################################################################
// Funciones publicas.

void init_piezo(){
	int16u i;
	bff.last = 0;
	
	for(i = 0; i < PIEZO_BUFSIZE; i++){
		shotVals[i] = NOSHOT;
	}
}

void get_shot(){
	ADC_ANALOG_Measure(TRUE);
	ADC_ANALOG_GetChanValue(CH_PIEZO,&bff.piezo);
	ADC_ANALOG_GetChanValue(CH_DETECT,&bff.detector);
}

void send_shot(){
	int8u correction = 0;
	_trama t;
	t.t[0] = PIEZO;
	t.t[1] = __get_shotVal();
	t.tam = 1;
	if (t.t[1] != NOSHOT)
		send_data(&t, correction);
}

///#################################################################################
// Funciones privadas

int8u __get_shotVal(){
	int8u shotVal, i = 1;
	bool shot = true;				//true si no hay ningun shot en el buffer
	
	while(i < PIEZO_BUFSIZE && shot){
		if(bff.shotVals[(bff.last + i++) % PIEZO_BUFSIZE] != NOSHOT) shot = false;
	}
		
	if(bff.piezo < (SOFT - .5)*MAXVALUE/3 || bff.piezo < bff.detector || !shot){
		bff.shotVals[bff.last] = NOSHOT;
	}
	else if((bff.piezo >= (SOFT - .5)*MAXVALUE/3) && (bff.piezo < (MEDIUM - .5)*MAXVALUE/3)){
		bff.shotVals[bff.last] = SOFT;
	}
	else if((bff.piezo >= (MEDIUM - .5)*MAXVALUE/3) && (bff.piezo < (HARD - .5)*MAXVALUE/3)){
		bff.shotVals[bff.last] = MEDIUM;
	}
	else{
		bff.shotVals[bff.last] = HARD;
	}
	shotVal = bff.shotVals[bff.last];
	bff.last++;
	bff.last %= PIEZO_BUFSIZE;
	return shotVal;
}

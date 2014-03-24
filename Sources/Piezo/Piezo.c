/*
 * Piezo.c
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */

#include "Piezo/Piezo.h"
#include "Comm/SerialComm.h"


//Constantes.

#define NOSHOT			0
#define SOFT			1u
#define MEDIUM			2u
#define HARD			3u
#define MAXVALUE		255
#define CH_PIEZO		4u
#define CH_DETECT		5u
#define PIEZO_BUFSIZE	16u	


//tipos

typedef struct{
	int8u detector;
	int8u piezo;
	int8u shotVals[PIEZO_BUFSIZE];
	int8u last;
}__piezo_data;

__piezo_data buf;


///#################################################################################
// Funciones publicas.

void init_piezo(){
	buf.last = 0;	
}

void get_shot(){
	ADC_ANALOG_Measure(TRUE);
	ADC_ANALOG_GetChanValue(CH_PIEZO,&buf.piezo);
	ADC_ANALOG_GetChanValue(CH_DETECT,&buf.detector);
}

void send_shot(int8u shotVal){
	int8u correction = 0;
	_trama t;
	t.t[0] = __get_shotVal();
	t.tam = 1;
	send_data(&t, correction);
}

///#################################################################################
// Funciones privadas

int8u __get_shotVal(){
	int8u i = 1, shotVal;
	bool shot = 1;
	
	while(i < PIEZO_BUFSIZE && shot){
		if(buf.shotVals[(buf.last + i++) % PIEZO_BUFSIZE] != NOSHOT) shot = 0;
	}
		
	if(buf.piezo < SOFT*MAXVALUE/3 || buf.piezo < buf.detector || !shot){
		buf.shotVals[last] = NOSHOT;
	}
	else if((buf.piezo >= SOFT*MAXVALUE/3) && (buf.piezo < MEDIUM*MAXVALUE/3)){
		buf.shotVals[last] = SOFT;
	}
	else if((buf.piezo >= MEDIUM*MAXVALUE/3) && (buf.piezo < HARD*MAXVALUE/3)){
		buf.shotVals[last] = MEDIUM;
	}
	else{
		buf.shotVals[last] = HARD;
	}
	shotVal = buf.shotVals[last];
	++last %= PIEZO_BUFSIZE;
	return shotVal;
}

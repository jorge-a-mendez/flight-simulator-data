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
#define SUBIDA			0u
#define BAJADA			1u
#define PIEZO_BUFSIZE	32u	



typedef struct{
	int8u piezo;									//< Valor de la se;al del piezoelectrico.
	int8u shotVals[PIEZO_BUFSIZE];					//< Valores de disparos anteriores
	int8u last;										//< Ultimo elemento en la cola.
	int8u prevVal;									//< Valor anterior leido del ADC.
	int8u status;									//< Subida o bajada.
}__piezo_data;

__piezo_data bff;

int8u __get_shotVal(void);								//< Retorna el valor a la intensidad del golpe
int8u __get_peak(void);									//< Si detecta un pico, retorna el valor de disparo.


///#################################################################################
// Funciones publicas.

void init_piezo(){
	int16u i;
	bff.last = 0;
	bff.prevVal = MAXVALUE;
	bff.status = BAJADA;
	for(i = 0; i < PIEZO_BUFSIZE; i++){
		bff.shotVals[i] = NOSHOT;
	}
}

void get_shot(){
	//ADC_ANALOG_Measure(TRUE);
	ADC_ANALOG_GetChanValue(CH_PIEZO,&bff.piezo);
}

void send_shot(){
	int8u correction = 0;
	_trama t;
	t.t[0] = PIEZO;
	t.t[1] = __get_peak();
	t.tam = 2;
	if (t.t[1] != NOSHOT)
		send_data(&t, correction);
}

///#################################################################################
// Funciones privadas


int8u __get_peak(){
	int8u shotVal;
	switch(bff.status){
		case SUBIDA:
			if(bff.piezo <= bff.prevVal){
				shotVal = __get_shotVal();
				bff.status = BAJADA;
			}
		case BAJADA:
			if(bff.piezo > bff.prevVal){
				bff.status = SUBIDA;
			}
			shotVal = NOSHOT;
	}
	bff.shotVals[bff.last] = shotVal;
	bff.last++;
	bff.last %= PIEZO_BUFSIZE;
	return shotVal;
}

int8u __get_shotVal(){
	int8u shotVal, i = 1;
	bool shot = true;				//true si no hay ningun shot en el buffer
	
	while(i < PIEZO_BUFSIZE && shot){
		if(bff.shotVals[(bff.last + i++) % PIEZO_BUFSIZE] != NOSHOT) shot = false;
	}
		
	if(bff.prevVal < (SOFT - .5)*MAXVALUE/3 ||  !shot){
		shotVal = NOSHOT;
	}
	else if((bff.prevVal >= (SOFT - .5)*MAXVALUE/3) && (bff.prevVal < (MEDIUM - .5)*MAXVALUE/3)){
		shotVal = SOFT;
	}
	else if((bff.prevVal >= (MEDIUM - .5)*MAXVALUE/3) && (bff.prevVal < (HARD - .5)*MAXVALUE/3)){
		shotVal = MEDIUM;
	}
	else{
		shotVal = HARD;
	}
	return shotVal;
}

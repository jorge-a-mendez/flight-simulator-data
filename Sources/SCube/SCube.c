/*
 * SCube.c
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */


#include "SCube/SCube.h"
#include "Comm/SerialComm.h"
#include "Events.h"

//Constantes

#define CH_X			0u						
#define CH_Y			1u
#define CH_Z			2u
#define SCUBE_BUFSIZE	16u

typedef struct{
	int16u x[SCUBE_BUFSIZE];
	int16u y[SCUBE_BUFSIZE];
	int16u z[SCUBE_BUFSIZE];
	int8u last;
	int16u averageX;
	int16u averageY;
	int16u averageZ;
}__SCube_data;

typedef union{
	int16u period;
	int8u byte[2];
}__period;

__SCube_data buf;

void __calibrateSCube();
void __average();


///#################################################################################
// Funciones publicas.


void init_SCube(){
	buf.last = 0;
	__calibrateSCube();
}

void read_SCube(){
	FRQ_MSR_X_GetCaptureValue(&buf.x[last]);
	FRQ_MSR_Y_GetCaptureValue(&buf.y[last]);
	FRQ_MSR_Z_GetCaptureValue(&buf.z[last]);
	last++;
	last %= SCUBE_BUFSIZE;
}

void send_SCube(int8u panel){
	int8u correccion = 0, i;
	_trama t;
	__period period;
	trama t;
	t.t[0] = panel;
	switch(panel){
		case PANELX:
			period.period = buf.x[buf.last];
			break;
		case PANELY:
			period.period = buf.y[buf.last];
			break;
		case PANELZ:
			period.period = buf.z[buf.last];
			break;
	}
	for(i = 0; i < 2; i++){
		if(period.byte[i] == 0xFF){
			t.t[i+1] = 0xFE;
			correccion |= 1 << (1-i);
		}
		else{
			t.t[i+1] = period.byte[i];
		}
	}
	t.tam = i+1;
	send_data(&t,correccion);
}


//#################################################################################
// Funciones privadas.


void __calibrateSCube(){
	
}

void __average(){
	int8u i;
	buf.averageX = 0;
	buf.averageY = 0;
	buf.averageZ = 0;
	for(i = 0; i < SCUBE_BUFSIZE; i++){
		buf.averageX += buf.x[(buf.last + i) % SCUBE_BUFSIZE];
		buf.averageY += buf.y[(buf.last + i) % SCUBE_BUFSIZE];
		buf.averageZ += buf.z[(buf.last + i) % SCUBE_BUFSIZE];
	}
	buf.averageX /= SCUBE_BUFSIZE;
	buf.averageY /= SCUBE_BUFSIZE;
	buf.averageZ /= SCUBE_BUFSIZE;
}

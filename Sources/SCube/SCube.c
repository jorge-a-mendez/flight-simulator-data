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

#define CH_X			0u			//< I/O pins a los que se conectan X,Y,Z			
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
int16u __get_period();


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

void send_SCube(){
	
}


//#################################################################################
// Funciones privadas.


void __calibrateSCube(){
	
}

int16u __get_period(){
	
}

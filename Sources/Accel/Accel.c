/* ###################################################################################
 * Accel.c
 * 		
 * 		This module contains the functions needed to measure tilting using
 * 		an analog 3 axis accelerometer designed by Freescale. It includes some
 * 		processing functions and transmission functions to simplify the
 * 		communication with the computer.
 * 		
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * ###################################################################################
 */

#include "Accel/Accel.h"
#include "Comm/SerialComm.h"
#include "Events.h"

#define 	ACCEL_BUFSIZE	64
#define 	ANGLE_XZ		0u		//< Data Identifiers needed for the communication.
#define 	ANGLE_YZ		1u
#define 	CH_X			1u
#define 	CH_Y			2u
#define 	CH_Z			3u

#define 	ZG				127		//< 0g value.

typedef struct {					//< Private struct for data buffering
	int8u x[ACCEL_BUFSIZE];			//< Array to save the samples of every axis.
	int8u y[ACCEL_BUFSIZE];
	int8u z[ACCEL_BUFSIZE];
	int16u last;					//< Index of the last element in the array.
	int32s averageX;				//< Averages of the samples of each axis.
	int32s averageY;
	int32s averageZ;
	int16u datos;					//< Number of samples taken since the last time the data was sent.
}__accel_data;

typedef union {						//< Private union for byte access of angle data.
	float x;
	int8u byte[4];
} __angle;

// Module's Global Variables.

__accel_data buffer; 				//< Buffer to keep the acquired data.		
bool datalista;						//< Boolean to signal when the data's ready to be sent.


//######################################################################################

//		Private Functions.

// #####################################################################################

float __calculateAngle(int8u ang);
void __average_accel();
void __filter_data();
void __calibrate();
void __send_angle(int8u ang);
void __send_avgs();

//######################################################################################

//		Public Functions.

// #####################################################################################

void init_accel(){
	buffer.last = 0;
	buffer.datos = 0;
	__calibrate();			//< Para hallar el valor de 0g.
	datalista = false;
}

bool accel_data_lista() {
	return datalista;
}

void read_accel(){
	
	// Se guarda el ultimo valor para hacer mas eficiente el calculo del promedio
	int16s x, y, z;
	int16s fix;
	buffer.last++;
	buffer.last %= ACCEL_BUFSIZE;
	
	x = buffer.x[buffer.last];
	y = buffer.y[buffer.last];
	z = buffer.z[buffer.last];
	
	ADC_ANALOG_GetChanValue(CH_X, &buffer.x[buffer.last]);
	ADC_ANALOG_GetChanValue(CH_Y, &buffer.y[buffer.last]);
	ADC_ANALOG_GetChanValue(CH_Z, &buffer.z[buffer.last]);
	
	fix = x - buffer.x[buffer.last];
	buffer.averageX = buffer.averageX - fix;
	fix = y - buffer.y[buffer.last];
	buffer.averageY = buffer.averageY - fix;
	fix = z - buffer.z[buffer.last];
	buffer.averageZ = buffer.averageZ - fix;
	
	buffer.datos++;
	if (buffer.datos == ACCEL_BUFSIZE) {
		datalista = true;
		buffer.datos = 0;
	}
}

void send_angles(){
	if (!datalista) return;
	__send_angle(0);
	__send_angle(1);
	datalista = false;
}

//######################################################################################

//		Private Functions Implementation.

// #####################################################################################

/**
 * __calculateAngle calcula la tangente cuadrada del angulo deseado a partir de un
 * subconjunto de muestras del buffer. 
 * 
 */


/*
 *	Para el filtrado... Se considera lo siguiente:
 *	
 *	Los cambios de inclinacion son lentos, tal vez un maximo de 2Hz.
 *	Las mediciones resultantes de aceleraciones dinamicas son aun mas lentos: Parece logico pensar esto ya que son
 *	el resultado de reflejos durante el juego. 
 *	
 *	Con esto es posible disminuir los errores dados por aceleraciones dinamicas, si se toma el promedio de las 
 *	muestras en 1/4 segundo. Si en ese tiempo ocurrio un numero peque;o de saltos por aceleraciones dinamicas, 
 *	entonces deberian ser disminuidas por los valores debido a aceleraciones estaticas. 
 * 
 * */

float __calculateAngle(int8u angle){
	int8u i;
	float x = 0, y = 0, z = 0, signo = 1;
	
	x = buffer.averageX - (float)ZG * ACCEL_BUFSIZE;
	y = buffer.averageY - (float)ZG * ACCEL_BUFSIZE;
	z = buffer.averageZ - (float)ZG * ACCEL_BUFSIZE;
	
	switch(angle){
	case ANGLE_XZ:
		if (y < 0) signo = -1;
		return ((y * y * signo))/(x * x + z * z);				 		//< Se manda sgn(y) * tan^2
	case ANGLE_YZ:
		if (x < 0) signo = -1;
		return ((x * x * signo))/(y * y + z * z);
	}
}


void __calibrate(){
	int16u i;
	float avx = 0, avy = 0, avz = 0;
	
	for(i = 0; i < ACCEL_BUFSIZE; i++){
		ADC_ANALOG_Measure(TRUE);
		ADC_ANALOG_GetChanValue(CH_X, &buffer.x[i]);
		ADC_ANALOG_GetChanValue(CH_Y, &buffer.y[i]);
		ADC_ANALOG_GetChanValue(CH_Z, &buffer.z[i]);
		avx += (float) buffer.x[i];
		avy += (float) buffer.y[i];
		avz += (float) buffer.z[i];
	}
	buffer.averageX = avx;
	buffer.averageY = avy;
	buffer.averageZ = avz;
}

void __average_accel(){
	int32u avx = 0, avy = 0, avz = 0;
	int16u i;
	
	for(i = 0; i < ACCEL_BUFSIZE; i++){
		avx += buffer.x[i];
		avy += buffer.y[i];
		avz += buffer.z[i];
	}
	
	buffer.averageX = avx / ACCEL_BUFSIZE;
	buffer.averageY = avy / ACCEL_BUFSIZE;
	buffer.averageZ = avz / ACCEL_BUFSIZE;
}

void __send_angle(int8u ang){					//< Envia un float que contiene la tangente cuadrada del angulo deseado.
	int8u i, correction = 0;
	_trama t;
	__angle angle;
	angle.x = __calculateAngle(ang);
	t.t[0] = ACCEL_ANGLE_XZ + ang;
	for (i = 0; i < 4; i++){
		if(angle.byte[i] == 0xFF){
			t.t[i + 1] = 0xFE;
			correction |= 1<<(3 - i);			//< Los ultimos 4bits corresponden al byte que necesita correccion 	
		}
		else t.t[i + 1] = angle.byte[i];
	}
	t.tam = i + 1; 
	send_data(&t, correction);
}


/* ###################################################################################
 * Accel.c
 *		Este modulo implementa las funciones y procedimientos necesarias
 *		para la adquisicion, procesamiento y transmision de datos provenientes
 *		del acelerometro de 3 ejes de Freescale.
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * ###################################################################################
 */

#include "Accel/Accel.h"
#include "Comm/SerialComm.h"
#include "Events.h"

#define 	ACCEL_BUFSIZE	64u
#define 	ANGLE_XZ		0u			//< Constantes para seleccionar angulo a medir o enviar.
#define 	ANGLE_YZ		1u
#define 	CH_X			1u
#define 	CH_Y			2u
#define 	CH_Z			3u

#define 	ZG				2252u		//< Puede ser sustituido por el nombre de alguna variable que almacene el valor de 0g dinamicamente.

typedef struct {					//< Private struct for data buffering
	int16u x[ACCEL_BUFSIZE];
	int16u y[ACCEL_BUFSIZE];
	int16u z[ACCEL_BUFSIZE];
	int8u last;
	int16u averageX;
	int16u averageY;
	int16u averageZ;
}__accel_data;

typedef union {		//< Private union for byte access of angle data.
	float x;
	int8u byte[4];
} __angle;

static __accel_data buf; 


//Funciones privadas

float __calculateAngle(int8u ang);
void __average();
void __filter_data();
void __calibrate();

//Funciones Publicas

void init_accel(){
	buf.last = 0;
	__calibrate();			//< Para hallar el valor de 0g.
}

void read_accel(){
	ADC_ANALOG_Measure(TRUE);
	ADC_ANALOG_GetChanValue(CH_X, &buf.x[buf.last]);
	ADC_ANALOG_GetChanValue(CH_Y, &buf.y[buf.last]);
	ADC_ANALOG_GetChanValue(CH_Z, &buf.z[buf.last]);
	buf.last++;
	buf.last %= ACCEL_BUFSIZE;
}

void send_angle(int8u ang){		//< Envia un float que contiene la tangente cuadrada del angulo deseado.
	int8u i, correction = 0;
	_trama t;
	__angle angle;
	angle.x = __calculateAngle(ang);
	t.t[0] = ACCEL_ANGLE_XZ + ang;
	for (i = 0; i < 4; i++){
		if(angle.byte[i] == 0xFF){
			t.t[i + 1] = 0xFE;
			correction |= 1<<(3 - i);
		}
		else t.t[i + 1] = angle.byte[i];
	}
	t.tam = i + 1; 
	send_data(&t, correction);
}

//#####################################################################################

/**
 * __calculateAngle calcula la tangente cuadrada del angulo deseado a partir de un
 * subconjunto de muestras del buf. 
 * 
 */


float __calculateAngle(int8u angle){
	int8u i;
	int32u x = 0, y = 0, z = 0;
	for(i = 0; i < ACCEL_BUFSIZE/2; i++){
		x += buf.x[(i + buf.last) % ACCEL_BUFSIZE] - ZG;
		y += buf.y[(i + buf.last) % ACCEL_BUFSIZE] - ZG;
		z += buf.z[(i + buf.last) % ACCEL_BUFSIZE] - ZG;
	}
	switch(angle){
	case ANGLE_XZ:
		return ((float)(y * y))/(float)(x * x + z * z);
	case ANGLE_YZ:
		return ((float)(x * x))/(float)(y * y + z * z);
	}
}

void __calibrate(){
	int8u i;
	int32u avx = 0, avy = 0, avz = 0;
	
	for(i = 0; i < ACCEL_BUFSIZE; i++){
		ADC_ANALOG_Measure(TRUE);
		ADC_ANALOG_GetChanValue(CH_X, &buf.x[i]);
		ADC_ANALOG_GetChanValue(CH_Y, &buf.y[i]);
		ADC_ANALOG_GetChanValue(CH_Z, &buf.z[i]);
		avx += buf.x[i];
		avy += buf.y[i];
		avz += buf.z[i];
	}
	buf.averageX = avx / ACCEL_BUFSIZE;
	buf.averageY = avy / ACCEL_BUFSIZE;
	buf.averageZ = avz / ACCEL_BUFSIZE;
}

void __average(){
	int32u avx = 0, avy = 0, avz = 0;
	int8u i;
	
	for(i = 0; i < ACCEL_BUFSIZE; i++){
		avx += buf.x[i];
		avy += buf.y[i];
		avz += buf.z[i];
	}
	
	buf.averageX = avx / ACCEL_BUFSIZE;
	buf.averageY = avy / ACCEL_BUFSIZE;
	buf.averageZ = avz / ACCEL_BUFSIZE;
}


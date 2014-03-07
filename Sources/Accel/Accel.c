/* ###################################################################################
 * Accel.c
 *
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * ###################################################################################
 */

#include "Accel/Accel.h"
#include "SerialComm.h"

#define ACCEL_BUFSIZE	64u
#define ANGLE_XZ		0u			//< Constantes para seleccionar angulo a medir o enviar.
#define ANGLE_YZ		1u
#define CH_X			1u
#define CH_Y			2u
#define CH_Z			3u

typedef struct {					//< Private struct for data buffering
	int8u x[ACCEL_BUFSIZE];
	int8u y[ACCEL_BUFSIZE];
	int8u z[ACCEL_BUFSIZE];
	int8u last;
}__accel_data;

typedef union {		//< Private union for byte access to angle data.
	float x;
	int8u byte[4];
} __angle;

static __accel_data buffer; 


//Funciones privadas

void __calculateAngle();
void __average();
void __filter_data();

//Funciones Publicas

void init_accel(){
	int8u i;
	buffer.last = 0;
	for (i = 0; i < ACCEL_BUFSIZE; i++){
		buffer.x[i] = 0;		//< Inicializando buffer en 0.
		buffer.y[i] = 0;
		buffer.z[i] = 0;
	}
}

void read_accel(){
	ADC_ANALOG_Measure(TRUE);
	ADC_ANALOG_GetChanValue(CH_X, &buffer.x[buffer.last]);
	ADC_ANALOG_GetChanValue(CH_Y, &buffer.y[buffer.last]);
	ADC_ANALOG_GetChanValue(CH_Z, &buffer.z[buffer.last]);
	buffer.last++;
	buffer.last %= ACCEL_BUFSIZE;
}

void send_angle(int8u ang){
	int8u i, correction = 0;
	_trama t;
	__angle angle;
	angle.x = __calculateAngle(ang);
	t.t[0] = ACCEL_ANGLE + ang;
	for (i = 0; i < 4; i++){
		if(angle.byte[i] == 0xFF){
			t.t[i + 1] = 0xFE;
			correction |= 1<<(3 - i);
		}
		else t.t[i + 1] = angle.byte[i];
	}
	t.size = i + 1; 
	send_data(&t, correction);
}

//#####################################################################################

float __calculateAngle(int8u angle){
	
}



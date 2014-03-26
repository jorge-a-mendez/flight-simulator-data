/*
 * Application.c
 *
 *  Created on: Mar 26, 2014
 *      Author: Rafael Rodriguez
 */


#include "Application.h"

//Tipo de datos privados

#define  ENVIAR 	0u					//< Envia datos al PC
#define  ESPERAR	1u					//< Estado de espera por un cambio de estado.
#define  LEER		2u					//< Se leen los datos. Se almacena en los buffers...
#define  RECIBIR 	3u					//< Se lee datos provenientes del PC.
#define  ADQUIRIR   4u					//< Solicita medicion de datos.

#define  ALL_DATA   1					//< Cantidad de medidas que se tienen que esperar.


int8u estado;
int8u data_lista;


//Funciones privadas..

void __send_info();
void __acquire();
void __read_info();

//Funciones publicas...


void init(){					//< Aqui van incluidas las funciones de inicializacion de los modulos.
	init_accel();
}

void state_machine(){
	data_lista = 0;
	estado = ESPERAR;
	for(;;) {
		switch(estado){
		case ESPERAR:
			if(data_lista == ALL_DATA){
				data_lista = 0;
				estado = LEER;
			}
			break;
		case ADQUIRIR:
			__acquire();
			estado = ESPERAR;
			break;
		case LEER:
			__read_info();
			estado = ESPERAR;
			break;
		case RECIBIR:
			break;
		case ENVIAR:
			__send_info();
			estado = ESPERAR;
			break;
		}
	}
}

void __acquire(){										//< Esta funcion solicita los datos a adquiri: ADC, Periodo.
	int8u error;
	if(estado == ADQUIRIR){
		error = ADC_ANALOG_Measure(FALSE);			//< Solicita conversion de todos los canales del ADC. No espera por el resultado.
		//Solicitud de medicion de los periodos.
		estado = ESPERAR;							//< La maquina espera por los resultados
	}
}

void __send_info(){				//< Encapsula todos los envios necesarios a la PC
	send_angles();	
}

void __read_info(){
	read_accel();
}

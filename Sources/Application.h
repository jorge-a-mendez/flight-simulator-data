/*###############################################################################
 * Application.c
 *		This module contains the main application design for the HCS08 
 *		to acquire and process the data from the sensors. 
 *		Here is implemented a simple state machine to acquire, process and
 *		send the data from the piezoelectric, the plates of the capacitive
 *		sensors and the signals from each axis of the Freescale Accelerometer. 
 *
 *		Authors:
 *			Rafael Rodriguez (rafaelrs307@gmail.com)
 *			Jorge Mendez (jorgeamendezm@gmail.com)
 *
 *###############################################################################*/


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Events.h"
#include "types.h"
#include "Comm/SerialComm.h"
#include "Accel/Accel.h"
#include "Piezo/Piezo.h"
#include "SCube/SCube.h"


#define  ENVIAR 	0u					//< Envia datos al PC
#define  ESPERAR	1u					//< Estado de espera por un cambio de estado.
#define  LEER		2u					//< Se leen los datos. Se almacena en los buffers...
#define  RECIBIR 	3u					//< Se lee datos provenientes del PC.
#define  ADQUIRIR   4u					//< Solicita medicion de datos.

extern int8u data_lista;
extern int8u estado;

void init();					//< Inicializa los modulos.
void state_machine();			//< Maquina de estados.

#endif /* APPLICATION_H_ */

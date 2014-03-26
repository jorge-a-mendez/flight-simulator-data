/*
 * Application.h
 *
 *  Created on: Mar 26, 2014
 *      Author: Rafael Rodriguez
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Events.h"
#include "types.h"
#include "Comm/SerialComm.h"
#include "Accel/Accel.h"
#include "Piezo/Piezo.h"
#include "SCube/SCube.h"

void init();					//< Inicializa los modulos.
void state_machine();			//< Maquina de estados.

#endif /* APPLICATION_H_ */

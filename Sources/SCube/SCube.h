/*###############################################################################
 * SCube.c
 *		This module contains the functions used to acquire the data from 
 *		capacitive sensor to locate position in a 3D space. It measures
 *		the time of charge and discharge controlling the state of a simple
 *		digital input/output pin.
 *		Authors:
 *			Rafael Rodriguez (rafaelrs307@gmail.com)
 *			Jorge Mendez (jorgeamendezm@gmail.com)
 *
 *###############################################################################*/


#ifndef SCUBE_H_
#define SCUBE_H_

#include "types.h"


///#################################################################################

// 									Public functions.

// #################################################################################

void init_SCube();			//< Initialise the SCube data structures.
void read_SCube();			//< Reads the information of each plate.
void send_SCube();			//< Sends the data acquired to the PC to be used.
bool Scube_data_lista();	//< Boolean function that signals when the data's ready to be sent.


#endif /* SCUBE_H_ */

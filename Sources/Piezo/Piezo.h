/*
 * Piezo.h
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */

#ifndef PIEZO_H_
#define PIEZO_H_


#include "types.h"

//########################################################################################

// Public Functions.

//########################################################################################

void init_piezo();
void get_shot();
void send_shot();
bool piezo_data_lista();

#endif /* PIEZO_H_ */

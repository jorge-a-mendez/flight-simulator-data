/*
 * Piezo.h
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */

#ifndef PIEZO_H_
#define PIEZO_H_


#include "types.h"



///#################################################################################
// Funciones publicas.

void init_piezo();
void get_shot(bool cmp1, bool cmp2, bool cmp3);
void send_shot();

#endif /* PIEZO_H_ */

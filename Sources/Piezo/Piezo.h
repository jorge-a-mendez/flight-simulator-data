/*
 * Piezo.h
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */

#ifndef PIEZO_H_
#define PIEZO_H_

//Constantes.

#define NOSHOT		0
#define SOFT		1u
#define MEDIUM		2u
#define HARD		3u
#define MAXVALUE	255
#define PIEZO_CH	0x01
#define BUF_SIZE	100

///#################################################################################
// Funciones publicas.

byte get_shot();

#endif /* PIEZO_H_ */

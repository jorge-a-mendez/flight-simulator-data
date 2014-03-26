/*
 * SCube.h
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */

#ifndef SCUBE_H_
#define SCUBE_H_

#include "types.h"

//Constantes

#define Kf		1			//< Constante para calcular capacitancia (C = Kf/f)
#define CH_X				//< I/O pins a los que se conectan X,Y,Z			
#define CH_Y	
#define CH_Z	

//Valores representativos del SCube

typedef struct struct_SCube{
	int mx;
	int bx;
	int my;
	int by;
	int mz;
	int mb;
}SCube;
//Se me ocurre que tal vez se puede aproximar (con suerte) a que los cambios en la
//capacitancia son lineales. Entonces calibrar podria ser pegar la mano a cada una
//de las placas y luego al extremo opuesto y fijar pendientes y puntos de corte de
//cada capacitancia en funcion de la distancia. Asi tendriamos una relacion directa
//para obtener las distancias dada una capacitancia. 


///#################################################################################
// Funciones publicas.

void init_SCube();
void read_SCube();
void send_SCube();



#endif /* SCUBE_H_ */

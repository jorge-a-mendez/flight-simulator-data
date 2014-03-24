/*
 * SCube.h
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */

#ifndef SCUBE_H_
#define SCUBE_H_

//Constantes

#define Kf		1			//< Constante para calcular capacitancia (C = f*Kf)
#define X		PTbla		//< I/O pins a los que se conectan X,Y,Z			
#define Y		PTbla
#define Z		PTbla

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

void calibrateSCube(SCube *cube);
byte* get_posX();
byte* get_posY();
byte* get_posZ();

//#################################################################################
// Funciones privadas.

//La idea que se me ocurre para medir f es que se tiene una onda cuadrada en un I/O
//y se espera a que cambie el valor que tenia inicialmente (para tomar el inicio del
//periodo). Luego se inicia un timer y se espera a que cambie el valor dos veces y
//el tiempo que haya tomado en cambiar esas dos veces seria el periodo.

int16u get_frequency(void* pin);
void waitOnNegValue(void* pin, bool initVal);
int16u get_capacitance(int16u f);


#endif /* SCUBE_H_ */

/*
 * SCube.c
 *
 *  Created on: Mar 3, 2014
 *      Author: Rafael Rodriguez
 */


///#################################################################################
// Funciones publicas.

void calibrateSCube(SCube *cube){
	
}

byte* get_posX(){
	
}

byte* get_posY(){
	
}

byte* get_posZ(){
	
}


//#################################################################################
// Funciones privadas.

int16u get_frequency(void* pin){
	waitOnNegVal(pin,(bool)(*pin));
	setTimer();
	waitOnNegVal(pin,(bool)(*pin));
	waitOnNegVal(pin,(bool)(*pin));
	stopTimer();					//habria que pasar el timer que sea creado en setTimer
	getTime();
}

void waitOnNegValue(void* pin, bool initVal){
	while((bool)(*pin) == initVal)	
}
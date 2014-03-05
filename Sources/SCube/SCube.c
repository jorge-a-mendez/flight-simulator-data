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
	setTimer();						//los tiempos dependeran del rango de frecuencias a usar.
									//tambien de eso dependera si se toman varios periodos o basta uno solo.
	waitOnNegVal(pin,(bool)(*pin));
	waitOnNegVal(pin,(bool)(*pin));
	stopTimer();					//habria que pasar el timer que sea creado en setTimer
	return getTime();
}

void waitOnNegValue(void* pin, bool initVal){
	while((bool)(*pin) == initVal)	
}

int16u get_capacitance(int16u f){
	return f*Kf;
}
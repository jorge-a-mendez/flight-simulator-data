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


#include "Application.h"


int8u estado;
int8u data_lista;

//######################################################################################

//		Private Functions.

// #####################################################################################

void __send_info();
void __acquire();
void __read_info();

//######################################################################################

//		Public Functions.

// #####################################################################################


/* #######################################################################################
 * 		Function: init. Initialize all the modules of the acquisition machine.
 * 		Parameters:
 * 			
 * 		Return:
 * 			
 * ######################################################################################## */

void init(){					//< This includes all the initialisation of the modules.
	init_accel();
	init_piezo();
	init_SCube();
}

/* #######################################################################################
 * 		Function: state_machine. State machine to acquire, preprocess and send
 * 				  the information to the pc.
 * 		Parameters:
 * 			
 * 		Return:
 * 			
 * ######################################################################################## */
void state_machine(){			//< State machine for the data acquisition and processing.
	data_lista = 0;
	estado = ESPERAR;
	for(;;) {
		switch(estado){
		case ESPERAR:
			if (accel_data_lista() || Scube_data_lista() || piezo_data_lista())
				estado = ENVIAR;
			break;
		case ADQUIRIR:
			__acquire();
			estado = ESPERAR;
			break;
		case LEER:
			__read_info();
			estado = ESPERAR;
			break;
		case RECIBIR:
			break;
		case ENVIAR:
			__send_info();
			estado = ESPERAR;
			break;
		}
	}
}

void __acquire(){									//< Initialise the acquisition process of the ADC
	int8u error;
	if(estado == ADQUIRIR){
		error = ADC_ANALOG_Measure(FALSE);			
		estado = ESPERAR;							//< Change the state of the machine: WAIT
	}
	read_SCube();
}

void __send_info(){									//< It sends any data that's ready to be sent to the PC.
	//send_angles();
	//send_shot();
	send_SCube();
}

void __read_info(){									//< Read the data from the ADC and the SCube plates.
	//read_accel();
	read_SCube();
}

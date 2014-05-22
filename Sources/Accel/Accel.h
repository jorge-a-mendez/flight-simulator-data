/* ###################################################################################
 * Accel.h
 * 		
 * 		This module contains the functions needed to measure tilting using
 * 		an analog 3 axis accelerometer designed by Freescale. It includes some
 * 		processing functions and transmission functions to simplify the
 * 		communication with the computer.
 * 		
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * ###################################################################################
 */

#ifndef ACCEL_H_
#define ACCEL_H_

#include "types.h"

void read_accel();					//< Read the value sampled by the ADC.
void send_angles();					//< Sends the pitch and roll squared tangent to the PC. It also includes the correspondent sign.
void init_accel();					//< Initialise the data structures of the module.
bool accel_data_lista();			//< Verify if is there any data to send.

#endif /* ACCEL_H_ */

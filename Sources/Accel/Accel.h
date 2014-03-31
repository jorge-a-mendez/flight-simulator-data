/* ###################################################################################
 * Accel.c
 *		Este modulo implementa las funciones y procedimientos necesarias
 *		para la adquisicion, procesamiento y transmision de datos provenientes
 *		del acelerometro de 3 ejes de Freescale.
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * ###################################################################################
 */

#ifndef ACCEL_H_
#define ACCEL_H_

#include "types.h"

void read_accel();					//< Toma un valor de cada eje del acelerometro.
void send_angles();					//< Calcula la tangente cuadrada del angulo deseado y lo envia al PC.
void init_accel();					//< Inicializa el buffer del acelerometro y calibra.

#endif /* ACCEL_H_ */

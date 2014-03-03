/*	############################################################################
 * 	SerialComm.h
 *	Modulo del protocolo de comunicacion con PC a traves de RS232
 *  Created on: Feb 28, 2014
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * #############################################################################
 */

#ifndef SERIALCOMM_H_
#define SERIALCOMM_H_

#include "types.h"

#define INICIAR	0x00		//< Caracter de inicio de comunicacion.
#define FIN		0xFF		//< Caracter de fin de comunicacion.

//< Type Code. 1 byte que representa el tipo de dato a enviar.

#define PANELX		1u			//< Paneles de los sensores capacitivos.
#define PANELY		2u
#define PANELZ  	3u
#define ACCEL_ANGLE	4u			//< Angulo medido mediante el acelerometro.
#define PIEZO		5u			//< 

//< Correction code. Posibles correcciones correspondiente a los datos enviados.

#define NO_CORRECTION	1u

#define 	BUF_SIZE 64		//< Tama;o del buffer para la comunicacion
#define 	RX_LED	 0x00		//< Mascara para LED de recepcion PTC0
#define 	TX_LED	 0x01		//< Mascara para LED de transmision PTC1

//RingBuffer para manejo de la comunicacion serial.

typedef struct struct_buffer{
	char buff[BUF_SIZE];
	int8u first;
	int8u last;	
	int8u size;
}buffer;

typedef struct struct_trama{
	int8u* t;
	int8u tam;
}_trama;

/* ###########################################################################

			PROCEDIMIENTOS PARA MANEJO DEL PROTOCOLO DE COMUNICACION

 * ###########################################################################*/

void init_buff();			//< Necesario llamar una vez para inicializacion del buffer
void heartbit();			//< Parpadeo de led para indicar envio y recepcion de datos. Llamado en evento HEARTBIT
void rx_handler();			//< Manejadores para la comunicacion serial.
void tx_handler();			

void send_data(_trama* data, int8u correction); //< Envia informacion a traves del puerto serial.
void read_data(_trama* data, int8u size);	//< Recibe informacion del puerto serial. BLOQUEANTE.

_trama* new_trama(int8u size);
void delete_trama(_trama* t);
void add_trama(_trama* t, int8u x);
void add_block(_trama* t, int8u x[]);


#endif /* SERIALCOMM_H_ */

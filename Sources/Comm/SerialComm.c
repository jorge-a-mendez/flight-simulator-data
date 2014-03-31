/*	###############################################################################
 * 	SerialComm.h
 *	Modulo del protocolo de comunicacion con PC a traves de RS232. (Implementacion)
 *  Created on: Feb 28, 2014
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * ################################################################################
 */


#include "Comm/SerialComm.h"
#include "Events.h"

//RingBuffer para manejo de la comunicacion serial.

typedef struct struct_buffer{
	char buff[BUF_SIZE];
	int8u first;
	int8u last;	
	int8u size;
}buffer;

static buffer bufTx;
int8u countRx, countTx;						//< Private variable. Debugging.

//#################################################################################
// Funciones privadas.

void __encola(buffer* t, char x);
char __desencola(buffer* t);

//#################################################################################

void init_buff() {
	bufTx.first = 0;
	bufTx.last = 0;
	bufTx.size = 0;
	countRx = 0;
	countTx = 0;
}

void tx_handler() {
	if(bufTx.size == 0) return;
	AS1_SendChar(__desencola(&bufTx));
}

void send_data(_trama* data, int8u correction){
	int8u i;
	__encola(&bufTx, INICIAR);
	for(i = 0; i < data->tam; i++)
		__encola(&bufTx, data->t[i]);
	__encola(&bufTx, correction);
	__encola(&bufTx, FIN);
}

/*
 * 	 La PC solo envia 4 bytes. INICIO -CODE 16bits- FIN.
 * 	 Esto se usa con objetivos de sincronizacion y solicitud de informacion si asi se desea.
 * 	 Retorna true si la data devuelta es una trama valida.
 */

bool read_data(_trama* data){			//< Es posible modificar este algoritmo para que en lugar de sobre escribir, se encole nueva data.
	int8u err;
	err = AS1_RecvBlock(data->t, TRAMA_SIZE, &data->tam);			//< Recibe el bloque.
	if(err == ERR_OK){
		//Chequea integridad del bloque recibido.
		if(data->tam != 4 && data->t[0] != INICIAR && data->t[3] != FIN) return false;
		countRx += 3;
		return true;
	}
	return false;
}

void heartbit(){
	if(countTx > 0){	
		TX_LED_NegVal();
		countTx--;
	}
	else 
		TX_LED_SetVal();
	if(countRx > 0){
		RX_LED_NegVal();
		countRx--;
	}
	else 
		RX_LED_SetVal();
}

//##################################################################################


void __encola(buffer* t, char x){
	while(t->size == BUF_SIZE) 
	{
		SCI1C2 |= 0x80;
	}
	t->buff[t->last] = x;
	++(t->last);
	t->last %= BUF_SIZE;
	t->size++;
	countTx += 3;
	if(t->size > BUF_SIZE) t->size = BUF_SIZE;
}

char __desencola(buffer* t){
	char x = t->buff[t->first];
	++(t->first);
	t->first %= BUF_SIZE;
	t->size--;
	return x;
}


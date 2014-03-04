/*	###############################################################################
 * 	SerialComm.h
 *	Modulo del protocolo de comunicacion con PC a traves de RS232. (Implementacion)
 *  Created on: Feb 28, 2014
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * ################################################################################
 */


#include "Comm/SerialComm.h"
#include "RX_LED.h"
#include "TX_LED.h"
#include "HEARTBIT.h"
#include "AS1.h"

static buffer bufTx;
static buffer bufRx;
//#################################################################################
// Funciones privadas.


void encola(buffer* t, char x);
char desencola(buffer* t);

//#################################################################################

void init_buff() {
	bufTx.first = 0;
	bufTx.last = 0;
	bufTx.size = 0;
	bufRx.first = 0;
	bufRx.last = 0;
	bufRx.size = 0;
}

void rx_handler(){
	char a;
	AS1_RecvChar(&a);
	encola(&bufRx, a);
}

void tx_handler() {
	if(bufTx.size == 0) return;
	AS1_SendChar(desencola(&bufTx));
}

void send_data(_trama* data, int8u correction){
	int8u i;
	encola(&bufTx, INICIAR);
	for(i = 0; i < data->tam; i++)
		encola(&bufTx, data->t[i]);
	encola(&bufTx, correction);
	encola(&bufTx, FIN);
}

void read_data(_trama* data, int8u size){
	return;		//< Falta implementacion...
}

void heartbit(){
	if(bufTx.size != 0)	
		TX_LED_NegVal();
	else TX_LED_SetVal();
	if(bufRx.size != 0)
		RX_LED_NegVal();
	else RX_LED_SetVal();
}

//##################################################################################


void encola(buffer* t, char x){
	while(t->size == BUF_SIZE);
	t->buff[t->last] = x;
	++(t->last);
	t->last %= BUF_SIZE;
	t->size++;
	if(t->size > BUF_SIZE) t->size = BUF_SIZE;
}

char desencola(buffer* t){
	char x = t->buff[t->first];
	++(t->first);
	t->first %= BUF_SIZE;
	t->size--;
	return x;
}

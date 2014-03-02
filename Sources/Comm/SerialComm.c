/*	###############################################################################
 * 	SerialComm.h
 *	Modulo del protocolo de comunicacion con PC a traves de RS232. (Implementacion)
 *  Created on: Feb 28, 2014
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * ################################################################################
 */


#include "./SerialComm.h"

static buffer bufTx;
static buffer bufRx;
//#################################################################################
// Funciones privadas.

void heartbit();		//< Parpadeo de led para indicar envio y recepcion de datos.
void encola(buffer* t, char x);
char desencola(buffer* t);

//#################################################################################

void init_buff() {
	bufTx.first = 0;
	bufTx.last = 0;
	bufRx.first = 0;
	bufRx.size = 0;
	bufRx.last = 0;
	bufRx.size = 0;
}

void rx_handler(){
	encola(&bufRx, AS1_RecvChar());
}

void tx_handler() {
	AS1_SendChar(desencola(&bufTx));
}

void send_data(string data, int8u correction){
	int8u i;
	encola(&bufTx, INICIAR);
	for(i = 0; data[i] != 0; i++)
		encola(&bufTx, data[i]);
	encola(&bufTx, FIN);
}

void read_data(string data, int8u size){
	return;		//< Falta implementacion...
}


//##################################################################################

void heartbit(){
	if(bufTx.size != 0)	
		TX_LED_NegVal();
	else TX_LED_SetVal();
	if(bufRx.size != 0)
		RX_LED_NegVal();
	else RX_LED_SetVal();
}

void encola(buffer* t, char x){
	t->buff[t->last] = x;
	++(t->last) %= BUF_SIZE;
	t->size++;
}

char desencola(buffer* t){
	char x = t->buff[t->first];
	++(t->first) %= BUF_SIZE;
	t->size--;
}

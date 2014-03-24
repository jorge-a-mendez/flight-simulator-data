/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-02-28, 15:06, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "AS1.h"
#include "RX_LED.h"
#include "TX_LED.h"
#include "HEARTBIT.h"
#include "ADC_ANALOG.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Comm/SerialComm.h"
#include "types.h"

typedef union{
	int8u b[2];
	int16u w;
}pot_amp;

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
 * Esta funcion es un programa de prueba para verificar funcionamiento del 
 * protocolo de comunicacion con la PC. Puede utilizarse para enviar cualquier
 * dato proveniente directamente de un canal del ADC
 * 
 */
void prueba_pot(_trama* a, pot_amp* measure, int8u* correction, bool* enviar){
	for(;;){
		  
	  ADC_ANALOG_MeasureChan(TRUE,0);
	  ADC_ANALOG_GetChanValue(0,&(measure->w));
	  a->t[0] = 1;
	  a->t[1] = measure->b[0];
	  if(measure->b[1] == 0xFF) {
		  a->t[2] = measure->b[1] - 1;
		  *correction = 2;
	  }
	  else a->t[2] = measure->b[1];
	  a->tam = 3;
	  send_data(a, *correction);
	  *enviar = false;
	  *correction = 0;	  
	}
}
  

void main(void)
{
  bool enviar;
  pot_amp measure;
  _trama a;
  int8u correction = 0;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  AS1_SendChar('i');		//< Activa la interrupcion de envio. 
  /* Write your code here */
  enviar = false;
  
  prueba_pot(&a, &measure, &correction, &enviar);

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/



/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

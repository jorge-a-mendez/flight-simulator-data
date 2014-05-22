/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ENVIAR.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : TimerInt
**     Version     : Component 02.160, Driver 01.23, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-22, 18:46, # CodeGen: 62
**     Abstract    :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings    :
**         Timer name                  : TPM2 (16-bit)
**         Compare name                : TPM21
**         Counter shared              : Yes
**
**         High speed mode
**             Prescaler               : divide-by-4
**             Clock                   : 6291456 Hz
**           Initial period/frequency
**             Xtal ticks              : 328
**             microseconds            : 10000
**             milliseconds            : 10
**             seconds (real)          : 0.010000069936
**             Hz                      : 100
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TPM2CNT   [$0051]
**              Mode                   : TPM2SC    [$0050]
**              Run                    : TPM2SC    [$0050]
**              Prescaler              : TPM2SC    [$0050]
**
**         Compare registers
**              Compare                : TPM2C1V   [$0059]
**
**         Flip-flop registers
**              Mode                   : TPM2C1SC  [$0058]
**     Contents    :
**         EnableEvent  - byte ENVIAR_EnableEvent(void);
**         DisableEvent - byte ENVIAR_DisableEvent(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __ENVIAR
#define __ENVIAR

/* MODULE ENVIAR. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

byte ENVIAR_EnableEvent(void);
/*
** ===================================================================
**     Method      :  ENVIAR_EnableEvent (component TimerInt)
**
**     Description :
**         This method enables the events.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define ENVIAR_DisableEvent() (TPM2C1SC_CH1IE = 0x00U, (byte)ERR_OK) /* Disable interrupt */
/*
** ===================================================================
**     Method      :  ENVIAR_DisableEvent (component TimerInt)
**
**     Description :
**         This method disables the events.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

__interrupt void ENVIAR_Interrupt(void);
/*
** ===================================================================
**     Method      :  ENVIAR_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the component event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void ENVIAR_Init(void);
/*
** ===================================================================
**     Method      :  ENVIAR_Init (component TimerInt)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END ENVIAR. */

#endif /* ifndef __ENVIAR */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

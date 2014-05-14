/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ENVIAR.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : TimerInt
**     Version     : Component 02.160, Driver 01.23, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-12, 14:39, # CodeGen: 54
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
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-64
**             Clock                   : 393216 Hz
**           Initial period/frequency
**             Xtal ticks              : 3277
**             microseconds            : 100001
**             milliseconds            : 100
**             seconds (real)          : 0.100001017253
**             Hz                      : 10
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

/* MODULE ENVIAR. */

#include "Events.h"
#include "PE_Error.h"
#include "ENVIAR.h"
#pragma MESSAGE DISABLE C2705          /* WARNING C2705: Possible loss of data */
#pragma MESSAGE DISABLE C5919          /* WARNING C5919: Conversion of floating to unsigned integral */
#pragma MESSAGE DISABLE C5703          /* WARNING C5703: Parameter X declared in function F but not referenced */
#pragma MESSAGE DISABLE C4002          /* Disable warning C4002 "Result not used" */

/*** Internal macros and method prototypes ***/

/*
** ===================================================================
**     Method      :  SetCV (component TimerInt)
**
**     Description :
**         The method computes and sets compare eventually modulo value 
**         for time measuring.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ENVIAR_SetCV(_Val) ( \
  TPM2MOD = (TPM2C1V = (word)(_Val)) )


/*** End of internal method prototypes ***/

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
byte ENVIAR_EnableEvent(void)
{
  if (TPM2C1SC_CH1IE == 0x00U) {
    /* TPM2C1SC: CH1F=0 */
    clrReg8Bits(TPM2C1SC, 0x80U);      /* Reset compare interrupt request flag */ 
  }
  /* TPM2C1SC: CH1IE=1 */
  setReg8Bits(TPM2C1SC, 0x40U);        /* Enable interrupt */ 
  return ERR_OK;                       /* OK */
}

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
/*
byte ENVIAR_DisableEvent(void)

**      This method is implemented as a macro. See header module. **
*/

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
void ENVIAR_Init(void)
{
  /* TPM2SC: TOF=0,TOIE=0,CPWMS=0,CLKSB=0,CLKSA=0,PS2=0,PS1=0,PS0=0 */
  setReg8(TPM2SC, 0x00U);              /* Stop HW; disable overflow interrupt and set prescaler to 0 */ 
  /* TPM2C1SC: CH1F=0,CH1IE=1,MS1B=0,MS1A=1,ELS1B=0,ELS1A=0,??=0,??=0 */
  setReg8(TPM2C1SC, 0x50U);            /* Set output compare mode and enable compare interrupt */ 
  ENVIAR_SetCV(0x9999U);               /* Initialize appropriate value to the compare/modulo/reload register */
  /* TPM2CNTH: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0 */
  setReg8(TPM2CNTH, 0x00U);            /* Reset HW Counter */ 
  /* TPM2SC: TOF=0,TOIE=0,CPWMS=0,CLKSB=0,CLKSA=1,PS2=1,PS1=1,PS0=0 */
  setReg8(TPM2SC, 0x0EU);              /* Set prescaler and run counter */ 
}


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
ISR(ENVIAR_Interrupt)
{
  /* TPM2C1SC: CH1F=0 */
  clrReg8Bits(TPM2C1SC, 0x80U);        /* Reset compare interrupt request flag */ 
  ENVIAR_OnInterrupt();                /* Invoke user event */
}



/* END ENVIAR. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

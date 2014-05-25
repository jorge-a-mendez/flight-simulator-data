/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CMP1.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : Capture
**     Version     : Component 02.216, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-24, 19:50, # CodeGen: 59
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TPM1
**             Counter shared          : No
**
**         High speed mode
**             Prescaler               : divide-by-4
**           Maximal time for capture register
**             Xtal ticks              : 341
**             microseconds            : 10417
**             milliseconds            : 10
**             seconds (real)          : 0.010416666667
**             Hz                      : 96
**           One tick of timer is
**             nanoseconds             : 166.666666666667
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TPM1C1V   [$0049]
**              Counter                : TPM1CNT   [$0041]
**              Mode                   : TPM1SC    [$0040]
**              Run                    : TPM1SC    [$0040]
**              Prescaler              : TPM1SC    [$0040]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       22            |  PTB5_TPM1CH1_SS1
**             ----------------------------------------------------
**
**         Port name                   : PTB
**         Bit number (in port)        : 5
**         Bit mask of the port        : $0020
**
**         Signal edge/level           : both
**         Priority                    : 
**         Pull option                 : off
**
**     Contents    :
**         GetPinValue - bool CMP1_GetPinValue(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE CMP1. */

#include "Events.h"
#include "CMP1.h"




/*
** ===================================================================
**     Method      :  CMP1_GetPinValue (component Capture)
**
**     Description :
**         The method reads the Capture pin value. The method is
**         available only if it is possible to read the pin value
**         (usually not available for internal signals).
**     Parameters  : None
**     Returns     :
**         ---             - Capture pin value.
**                           <true> - high level
**                           <false> - low level.
** ===================================================================
*/
/*
bool CMP1_GetPinValue(void)

**  This method is implemented as a macro. See CMP1.h file.  **
*/

/*
** ===================================================================
**     Method      :  CMP1_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CMP1_Init(void)
{
  /* TPM1SC: TOF=0,TOIE=0,CPWMS=0,CLKSB=0,CLKSA=0,PS2=0,PS1=0,PS0=0 */
  setReg8(TPM1SC, 0x00U);              /* Stop HW */ 
  /* TPM1MOD: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM1MOD, 0x00U);            /* Disable modulo register */ 
  /* TPM1CNTH: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0 */
  setReg8(TPM1CNTH, 0x00U);            /* Reset counter */ 
  /* TPM1C1V: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM1C1V, 0x00U);            /* Clear capture register */ 
  /* TPM1SC: PS2=0,PS1=1,PS0=0 */
  clrSetReg8Bits(TPM1SC, 0x05U, 0x02U); /* Set prescaler register */ 
  /* TPM1C1SC: CH1F=0,CH1IE=1,MS1B=0,MS1A=0,ELS1B=1,ELS1A=1,??=0,??=0 */
  setReg8(TPM1C1SC, 0x4CU);            /* Enable both interrupt and capture function */ 
  /* TPM1SC: CLKSB=0,CLKSA=1 */
  clrSetReg8Bits(TPM1SC, 0x10U, 0x08U); /* Run counter */ 
}


/*
** ===================================================================
**     Method      :  Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(CMP1_Interrupt)
{
  (void)TPM1C1SC;                      /* Dummy read to reset interrupt request flag */
  /* TPM1C1SC: CH1F=0 */
  clrReg8Bits(TPM1C1SC, 0x80U);        /* Reset interrupt request flag */ 
  CMP1_OnCapture();                    /* Invoke user event */
}



/* END CMP1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

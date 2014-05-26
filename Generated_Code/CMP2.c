/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CMP2.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : Capture
**     Version     : Component 02.216, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-26, 13:37, # CodeGen: 63
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
**             Counter shared          : Yes
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
**              Capture                : TPM1C2V   [$004C]
**              Counter                : TPM1CNT   [$0041]
**              Mode                   : TPM1SC    [$0040]
**              Run                    : TPM1SC    [$0040]
**              Prescaler              : TPM1SC    [$0040]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       48            |  PTA6_TPM1CH2_ADP8
**             ----------------------------------------------------
**
**         Port name                   : PTA
**         Bit number (in port)        : 6
**         Bit mask of the port        : $0040
**
**         Signal edge/level           : falling
**         Priority                    : 
**         Pull option                 : off
**
**     Contents    :
**         GetCaptureValue - byte CMP2_GetCaptureValue(CMP2_TCapturedValue *Value);
**         GetPinValue     - bool CMP2_GetPinValue(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE CMP2. */

#include "Events.h"
#include "CMP2.h"




/*
** ===================================================================
**     Method      :  CMP2_GetCaptureValue (component Capture)
**
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               166.666666666667 ns in high speed mode
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte CMP2_GetCaptureValue(CMP2_TCapturedValue *Value)

**  This method is implemented as a macro. See CMP2.h file.  **
*/

/*
** ===================================================================
**     Method      :  CMP2_GetPinValue (component Capture)
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
bool CMP2_GetPinValue(void)

**  This method is implemented as a macro. See CMP2.h file.  **
*/

/*
** ===================================================================
**     Method      :  CMP2_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CMP2_Init(void)
{
  /* TPM1C2V: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM1C2V, 0x00U);            /* Clear capture register */ 
  /* TPM1C2SC: CH2F=0,CH2IE=1,MS2B=0,MS2A=0,ELS2B=1,ELS2A=0,??=0,??=0 */
  setReg8(TPM1C2SC, 0x48U);            /* Enable both interrupt and capture function */ 
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
ISR(CMP2_Interrupt)
{
  (void)TPM1C2SC;                      /* Dummy read to reset interrupt request flag */
  /* TPM1C2SC: CH2F=0 */
  clrReg8Bits(TPM1C2SC, 0x80U);        /* Reset interrupt request flag */ 
  CMP2_OnCapture();                    /* Invoke user event */
}



/* END CMP2. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

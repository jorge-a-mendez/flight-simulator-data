/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ADC_ANALOG.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : ADC
**     Version     : Component 01.667, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-12, 12:48, # CodeGen: 44
**     Abstract    :
**         This device "ADC" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings    :
**          Component name                                 : ADC_ANALOG
**          A/D converter                                  : ADC
**          Sharing                                        : Disabled
**          Interrupt service/event                        : Enabled
**            A/D interrupt                                : Vadc
**            A/D interrupt priority                       : medium priority
**          A/D channels                                   : 6
**            Channel0                                     : 
**              A/D channel (pin)                          : PTA0_KBI1P0_TPM1CH0_ADP0_ACMP1PLUS
**              A/D channel (pin) signal                   : POT
**            Channel1                                     : 
**              A/D channel (pin)                          : PTA2_KBI1P2_SDA1_ADP2
**              A/D channel (pin) signal                   : ACCELX
**            Channel2                                     : 
**              A/D channel (pin)                          : PTA3_KBI1P3_SCL1_ADP3
**              A/D channel (pin) signal                   : ACCELY
**            Channel3                                     : 
**              A/D channel (pin)                          : PTB3_KBI1P7_MOSI1_ADP7
**              A/D channel (pin) signal                   : ACCELZ
**            Channel4                                     : 
**              A/D channel (pin)                          : PTF0_ADP10
**              A/D channel (pin) signal                   : PIEZO
**            Channel5                                     : 
**              A/D channel (pin)                          : PTF1_ADP11
**              A/D channel (pin) signal                   : 
**          A/D resolution                                 : Autoselect
**          Conversion time                                : 3.655752 �s
**          Low-power mode                                 : Disabled
**          Sample time                                    : short
**          Internal trigger                               : Disabled
**          Number of conversions                          : 1
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          High input limit                               : 1
**          Low input limit                                : 0
**          Get value directly                             : yes
**          Wait for result                                : yes
**     Contents    :
**         Measure      - byte ADC_ANALOG_Measure(bool WaitForResult);
**         MeasureChan  - byte ADC_ANALOG_MeasureChan(bool WaitForResult, byte Channel);
**         GetValue     - byte ADC_ANALOG_GetValue(void* Values);
**         GetChanValue - byte ADC_ANALOG_GetChanValue(byte Channel, void* Value);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __ADC_ANALOG
#define __ADC_ANALOG

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE ADC_ANALOG. */

#include "Cpu.h"



/* Constants for channel selection */
#define ADC_ANALOG_CHANNEL_POT          0
#define ADC_ANALOG_CHANNEL_ACCELX       1
#define ADC_ANALOG_CHANNEL_ACCELY       2
#define ADC_ANALOG_CHANNEL_ACCELZ       3
#define ADC_ANALOG_CHANNEL_PIEZO        4

__interrupt void ADC_ANALOG_Interrupt(void);
/*
** ===================================================================
**     Method      :  ADC_ANALOG_Interrupt (component ADC)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void ADC_ANALOG_HWEnDi(void);
/*
** ===================================================================
**     Method      :  ADC_ANALOG_HWEnDi (component ADC)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


byte ADC_ANALOG_Measure(bool WaitForResult);
/*
** ===================================================================
**     Method      :  ADC_ANALOG_Measure (component ADC)
**
**     Description :
**         This method performs one measurement on all channels that
**         are set in the component inspector. (Note: If the <number of
**         conversions> is more than one the conversion of A/D channels
**         is performed specified number of times.)
**     Parameters  :
**         NAME            - DESCRIPTION
**         WaitForResult   - Wait for a result of a
**                           conversion. If <interrupt service> is
**                           disabled, A/D peripheral doesn't support
**                           measuring all channels at once or Autoscan
**                           mode property isn't enabled and at the same
**                           time the <number of channels> is greater
**                           than 1, then the WaitForResult parameter is
**                           ignored and the method waits for each
**                           result every time. If the <interrupt
**                           service> is disabled and a <number of
**                           conversions> is greater than 1, the
**                           parameter is ignored and the method also
**                           waits for each result every time.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSY - A conversion is already running
** ===================================================================
*/

byte ADC_ANALOG_MeasureChan(bool WaitForResult,byte Channel);
/*
** ===================================================================
**     Method      :  ADC_ANALOG_MeasureChan (component ADC)
**
**     Description :
**         This method performs measurement on one channel. (Note: If
**         the <number of conversions> is more than one the conversion
**         of the A/D channel is performed specified number of times.)
**     Parameters  :
**         NAME            - DESCRIPTION
**         WaitForResult   - Wait for a result of
**                           conversion. If the <interrupt service> is
**                           disabled and at the same time a <number of
**                           conversions> is greater than 1, the
**                           WaitForResult parameter is ignored and the
**                           method waits for each result every time.
**         Channel         - Channel number. If only one
**                           channel in the component is set this
**                           parameter is ignored, because the parameter
**                           is set inside this method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSY - A conversion is already running
**                           ERR_RANGE - Parameter "Channel" out of range
** ===================================================================
*/

byte ADC_ANALOG_GetValue(void *Values);
/*
** ===================================================================
**     Method      :  ADC_ANALOG_GetValue (component ADC)
**
**     Description :
**         Returns the last measured values for all channels. Format
**         and width of the value is a native format of the A/D
**         converter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Values          - Pointer to the array that contains
**                           the measured data. Data type is a byte, a
**                           word or an int. It depends on the supported
**                           modes, resolution, etc. of the AD converter.
**                           See the Version specific information for
**                           the current CPU in <General Info>.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
** ===================================================================
*/

byte ADC_ANALOG_GetChanValue(byte Channel,void* Value);
/*
** ===================================================================
**     Method      :  ADC_ANALOG_GetChanValue (component ADC)
**
**     Description :
**         Returns the last measured value of the required channel.
**         Format and width of the value is a native format of the A/D
**         converter.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Channel         - Channel number. If only one
**                           channel in the component is set then this
**                           parameter is ignored.
**       * Value           - Pointer to the measured value. Data
**                           type is a byte, a word or an int. It
**                           depends on the supported modes, resolution,
**                           etc. of the AD converter. See the Version
**                           specific information for the current CPU in
**                           <General Info>.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_RANGE - Parameter "Channel" out of
**                           range
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
** ===================================================================
*/

void ADC_ANALOG_Init(void);
/*
** ===================================================================
**     Method      :  ADC_ANALOG_Init (component ADC)
**
**     Description :
**         Initializes the associated peripheral(s) and the component's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/



/* END ADC_ANALOG. */

#endif /* ifndef __ADC_ANALOG */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ADC_ANALOG.c" \
"../Generated_Code/ADQUIRIR.c" \
"../Generated_Code/AS1.c" \
"../Generated_Code/CMP1.c" \
"../Generated_Code/CMP2.c" \
"../Generated_Code/CMP3.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/ENVIAR.c" \
"../Generated_Code/HEARTBIT.c" \
"../Generated_Code/IO_Map.c" \
"../Generated_Code/RX_LED.c" \
"../Generated_Code/TX_LED.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/ADC_ANALOG.c \
../Generated_Code/ADQUIRIR.c \
../Generated_Code/AS1.c \
../Generated_Code/CMP1.c \
../Generated_Code/CMP2.c \
../Generated_Code/CMP3.c \
../Generated_Code/Cpu.c \
../Generated_Code/ENVIAR.c \
../Generated_Code/HEARTBIT.c \
../Generated_Code/IO_Map.c \
../Generated_Code/RX_LED.c \
../Generated_Code/TX_LED.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/ADC_ANALOG_c.obj \
./Generated_Code/ADQUIRIR_c.obj \
./Generated_Code/AS1_c.obj \
./Generated_Code/CMP1_c.obj \
./Generated_Code/CMP2_c.obj \
./Generated_Code/CMP3_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/ENVIAR_c.obj \
./Generated_Code/HEARTBIT_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/RX_LED_c.obj \
./Generated_Code/TX_LED_c.obj \
./Generated_Code/Vectors_c.obj \

OBJS_QUOTED += \
"./Generated_Code/ADC_ANALOG_c.obj" \
"./Generated_Code/ADQUIRIR_c.obj" \
"./Generated_Code/AS1_c.obj" \
"./Generated_Code/CMP1_c.obj" \
"./Generated_Code/CMP2_c.obj" \
"./Generated_Code/CMP3_c.obj" \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/ENVIAR_c.obj" \
"./Generated_Code/HEARTBIT_c.obj" \
"./Generated_Code/IO_Map_c.obj" \
"./Generated_Code/RX_LED_c.obj" \
"./Generated_Code/TX_LED_c.obj" \
"./Generated_Code/Vectors_c.obj" \

C_DEPS += \
./Generated_Code/ADC_ANALOG_c.d \
./Generated_Code/ADQUIRIR_c.d \
./Generated_Code/AS1_c.d \
./Generated_Code/CMP1_c.d \
./Generated_Code/CMP2_c.d \
./Generated_Code/CMP3_c.d \
./Generated_Code/Cpu_c.d \
./Generated_Code/ENVIAR_c.d \
./Generated_Code/HEARTBIT_c.d \
./Generated_Code/IO_Map_c.d \
./Generated_Code/RX_LED_c.d \
./Generated_Code/TX_LED_c.d \
./Generated_Code/Vectors_c.d \

C_DEPS_QUOTED += \
"./Generated_Code/ADC_ANALOG_c.d" \
"./Generated_Code/ADQUIRIR_c.d" \
"./Generated_Code/AS1_c.d" \
"./Generated_Code/CMP1_c.d" \
"./Generated_Code/CMP2_c.d" \
"./Generated_Code/CMP3_c.d" \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/ENVIAR_c.d" \
"./Generated_Code/HEARTBIT_c.d" \
"./Generated_Code/IO_Map_c.d" \
"./Generated_Code/RX_LED_c.d" \
"./Generated_Code/TX_LED_c.d" \
"./Generated_Code/Vectors_c.d" \

OBJS_OS_FORMAT += \
./Generated_Code/ADC_ANALOG_c.obj \
./Generated_Code/ADQUIRIR_c.obj \
./Generated_Code/AS1_c.obj \
./Generated_Code/CMP1_c.obj \
./Generated_Code/CMP2_c.obj \
./Generated_Code/CMP3_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/ENVIAR_c.obj \
./Generated_Code/HEARTBIT_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/RX_LED_c.obj \
./Generated_Code/TX_LED_c.obj \
./Generated_Code/Vectors_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ADC_ANALOG_c.obj: ../Generated_Code/ADC_ANALOG.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/ADC_ANALOG.args" -ObjN="Generated_Code/ADC_ANALOG_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/ADQUIRIR_c.obj: ../Generated_Code/ADQUIRIR.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/ADQUIRIR.args" -ObjN="Generated_Code/ADQUIRIR_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/AS1_c.obj: ../Generated_Code/AS1.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/AS1.args" -ObjN="Generated_Code/AS1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/CMP1_c.obj: ../Generated_Code/CMP1.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/CMP1.args" -ObjN="Generated_Code/CMP1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/CMP2_c.obj: ../Generated_Code/CMP2.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/CMP2.args" -ObjN="Generated_Code/CMP2_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/CMP3_c.obj: ../Generated_Code/CMP3.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/CMP3.args" -ObjN="Generated_Code/CMP3_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Cpu.args" -ObjN="Generated_Code/Cpu_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/ENVIAR_c.obj: ../Generated_Code/ENVIAR.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/ENVIAR.args" -ObjN="Generated_Code/ENVIAR_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/HEARTBIT_c.obj: ../Generated_Code/HEARTBIT.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/HEARTBIT.args" -ObjN="Generated_Code/HEARTBIT_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IO_Map_c.obj: ../Generated_Code/IO_Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/IO_Map.args" -ObjN="Generated_Code/IO_Map_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/RX_LED_c.obj: ../Generated_Code/RX_LED.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/RX_LED.args" -ObjN="Generated_Code/RX_LED_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TX_LED_c.obj: ../Generated_Code/TX_LED.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/TX_LED.args" -ObjN="Generated_Code/TX_LED_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Vectors.args" -ObjN="Generated_Code/Vectors_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '



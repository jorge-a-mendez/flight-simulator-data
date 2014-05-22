################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Application.c" \
"../Sources/Events.c" \
"../Sources/ProcessorExpert.c" \

C_SRCS += \
../Sources/Application.c \
../Sources/Events.c \
../Sources/ProcessorExpert.c \

OBJS += \
./Sources/Application_c.obj \
./Sources/Events_c.obj \
./Sources/ProcessorExpert_c.obj \

OBJS_QUOTED += \
"./Sources/Application_c.obj" \
"./Sources/Events_c.obj" \
"./Sources/ProcessorExpert_c.obj" \

C_DEPS += \
./Sources/Application_c.d \
./Sources/Events_c.d \
./Sources/ProcessorExpert_c.d \

C_DEPS_QUOTED += \
"./Sources/Application_c.d" \
"./Sources/Events_c.d" \
"./Sources/ProcessorExpert_c.d" \

OBJS_OS_FORMAT += \
./Sources/Application_c.obj \
./Sources/Events_c.obj \
./Sources/ProcessorExpert_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Application_c.obj: ../Sources/Application.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Application.args" -ObjN="Sources/Application_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Events.args" -ObjN="Sources/Events_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert_c.obj: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/ProcessorExpert.args" -ObjN="Sources/ProcessorExpert_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '



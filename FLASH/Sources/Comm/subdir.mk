################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Comm/SerialComm.c" \

C_SRCS += \
../Sources/Comm/SerialComm.c \

OBJS += \
./Sources/Comm/SerialComm_c.obj \

OBJS_QUOTED += \
"./Sources/Comm/SerialComm_c.obj" \

C_DEPS += \
./Sources/Comm/SerialComm_c.d \

C_DEPS_QUOTED += \
"./Sources/Comm/SerialComm_c.d" \

OBJS_OS_FORMAT += \
./Sources/Comm/SerialComm_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Comm/SerialComm_c.obj: ../Sources/Comm/SerialComm.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Comm/SerialComm.args" -ObjN="Sources/Comm/SerialComm_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Comm/%.d: ../Sources/Comm/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '



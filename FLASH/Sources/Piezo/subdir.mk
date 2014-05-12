################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Piezo/Piezo.c" \

C_SRCS += \
../Sources/Piezo/Piezo.c \

OBJS += \
./Sources/Piezo/Piezo_c.obj \

OBJS_QUOTED += \
"./Sources/Piezo/Piezo_c.obj" \

C_DEPS += \
./Sources/Piezo/Piezo_c.d \

C_DEPS_QUOTED += \
"./Sources/Piezo/Piezo_c.d" \

OBJS_OS_FORMAT += \
./Sources/Piezo/Piezo_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Piezo/Piezo_c.obj: ../Sources/Piezo/Piezo.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Piezo/Piezo.args" -ObjN="Sources/Piezo/Piezo_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Piezo/%.d: ../Sources/Piezo/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '



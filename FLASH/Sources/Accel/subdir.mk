################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Accel/Accel.c" \

C_SRCS += \
../Sources/Accel/Accel.c \

OBJS += \
./Sources/Accel/Accel_c.obj \

OBJS_QUOTED += \
"./Sources/Accel/Accel_c.obj" \

C_DEPS += \
./Sources/Accel/Accel_c.d \

C_DEPS_QUOTED += \
"./Sources/Accel/Accel_c.d" \

OBJS_OS_FORMAT += \
./Sources/Accel/Accel_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Accel/Accel_c.obj: ../Sources/Accel/Accel.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Accel/Accel.args" -ObjN="Sources/Accel/Accel_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Accel/%.d: ../Sources/Accel/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '



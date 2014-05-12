################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/SCube/SCube.c" \

C_SRCS += \
../Sources/SCube/SCube.c \

OBJS += \
./Sources/SCube/SCube_c.obj \

OBJS_QUOTED += \
"./Sources/SCube/SCube_c.obj" \

C_DEPS += \
./Sources/SCube/SCube_c.d \

C_DEPS_QUOTED += \
"./Sources/SCube/SCube_c.d" \

OBJS_OS_FORMAT += \
./Sources/SCube/SCube_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/SCube/SCube_c.obj: ../Sources/SCube/SCube.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/SCube/SCube.args" -ObjN="Sources/SCube/SCube_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/SCube/%.d: ../Sources/SCube/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '



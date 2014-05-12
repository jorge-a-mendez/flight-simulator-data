################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 21
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm" -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/SCube/subdir.mk
-include Sources/subdir.mk
-include Sources/Piezo/subdir.mk
-include Sources/Comm/subdir.mk
-include Sources/Accel/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Generated_Code/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ACQ-SCube.abs \

EXECUTABLES_QUOTED += \
"ACQ-SCube.abs" \

EXECUTABLES_OS_FORMAT += \
ACQ-SCube.abs \

BURNER_OUTPUT_OUTPUTS += \
ACQ-SCube.abs.s19 \

BURNER_OUTPUT_OUTPUTS_QUOTED += \
"ACQ-SCube.abs.s19" \

BURNER_OUTPUT_OUTPUTS_OS_FORMAT += \
ACQ-SCube.abs.s19 \


# All Target
call-burner := 0
ifneq ($(strip $(EXECUTABLES)),)
ifneq ($(strip $(BBL_SRCS_QUOTED)),)
call-burner := 1
endif
endif
ifeq ($(call-burner),1)
all: ACQ-SCube.abs ACQ-SCube.abs.s19
else
all: ACQ-SCube.abs
endif

# Tool invocations
ACQ-SCube.abs: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/ProcessorExpert.prm
	@echo 'Building target: $@'
	@echo 'Executing target #22 $@'
	@echo 'Invoking: S08 Linker'
	"$(HC08ToolsEnv)/linker" -ArgFile"ACQ-SCube.args" -O"ACQ-SCube.abs"
	@echo 'Finished building target: $@'
	@echo ' '

ACQ-SCube.abs.s19: $(BBL_SRCS) $(EXECUTABLES)
	@echo 'Executing target #23 $@'
	@echo 'Invoking: S08 Burner'
	"$(HC08ToolsEnv)/burner" -ArgFile"ACQ-SCube.abs.args" -f="$<" -env"ABS_FILE=$(strip $(EXECUTABLES_OS_FORMAT))"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) "./*/*.obj" "./*/*/*.obj"  $(CPP_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(CXX_DEPS_QUOTED) $(BURNER_OUTPUT_OUTPUTS_QUOTED) $(C_UPPER_DEPS_QUOTED) $(C++_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*.d" "./*/*/*.d"  $(ProjDirPath)/FLASH/ACQ-SCube.abs $(ProjDirPath)/FLASH/ACQ-SCube.abs.args $(ProjDirPath)/FLASH/ACQ-SCube.abs.s19 $(ProjDirPath)/FLASH/ACQ-SCube.args $(ProjDirPath)/FLASH/ACQ-SCube.map
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

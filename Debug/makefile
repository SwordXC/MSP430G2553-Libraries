################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Libraries/libraries/adc.obj" \
"./Libraries/libraries/exti.obj" \
"./Libraries/libraries/gpio.obj" \
"./Libraries/libraries/i2c.obj" \
"./Libraries/libraries/pit.obj" \
"./Libraries/libraries/pwm.obj" \
"./Libraries/libraries/uart.obj" \
"./Libraries/peripheral/FONT.obj" \
"./Libraries/peripheral/HT1621.obj" \
"./Libraries/peripheral/LCD.obj" \
"./Libraries/peripheral/OLED.obj" \
"./Libraries/peripheral/TCA6416A.obj" \
"./Project/CODE/knob.obj" \
"./Project/CODE/loop.obj" \
"./Project/CODE/menu.obj" \
"./Project/CODE/touch.obj" \
"./Project/USER/scr/isr.obj" \
"./Project/USER/scr/main.obj" \
"../lnk_msp430g2553.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Libraries/libraries/subdir_vars.mk
-include Libraries/peripheral/subdir_vars.mk
-include Project/CODE/subdir_vars.mk
-include Project/USER/scr/subdir_vars.mk
-include subdir_rules.mk
-include Libraries/libraries/subdir_rules.mk
-include Libraries/peripheral/subdir_rules.mk
-include Project/CODE/subdir_rules.mk
-include Project/USER/scr/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
msp430g2553.out \

EXE_OUTPUTS__QUOTED += \
"msp430g2553.out" \

BIN_OUTPUTS += \
msp430g2553.hex \

BIN_OUTPUTS__QUOTED += \
"msp430g2553.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "msp430g2553.out" secondary-outputs

# Tool invocations
msp430g2553.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP430 Linker'
	"E:/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp --use_hw_mpy=none --advice:power="all" --define=__MSP430G2553__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number -z -m"msp430g2553.map" --heap_size=80 --stack_size=80 -i"E:/ccs1230/ccs/ccs_base/msp430/include" -i"E:/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/lib" -i"E:/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="msp430g2553_linkInfo.xml" --use_hw_mpy=none --rom_model -o "msp430g2553.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

msp430g2553.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: MSP430 Hex Utility'
	"E:/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/hex430" --memwidth=16 --romwidth=16 --diag_wrap=off --intel -o "msp430g2553.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Libraries\libraries\adc.obj" "Libraries\libraries\exti.obj" "Libraries\libraries\gpio.obj" "Libraries\libraries\i2c.obj" "Libraries\libraries\pit.obj" "Libraries\libraries\pwm.obj" "Libraries\libraries\uart.obj" "Libraries\peripheral\FONT.obj" "Libraries\peripheral\HT1621.obj" "Libraries\peripheral\LCD.obj" "Libraries\peripheral\OLED.obj" "Libraries\peripheral\TCA6416A.obj" "Project\CODE\knob.obj" "Project\CODE\loop.obj" "Project\CODE\menu.obj" "Project\CODE\touch.obj" "Project\USER\scr\isr.obj" "Project\USER\scr\main.obj" 
	-$(RM) "Libraries\libraries\adc.d" "Libraries\libraries\exti.d" "Libraries\libraries\gpio.d" "Libraries\libraries\i2c.d" "Libraries\libraries\pit.d" "Libraries\libraries\pwm.d" "Libraries\libraries\uart.d" "Libraries\peripheral\FONT.d" "Libraries\peripheral\HT1621.d" "Libraries\peripheral\LCD.d" "Libraries\peripheral\OLED.d" "Libraries\peripheral\TCA6416A.d" "Project\CODE\knob.d" "Project\CODE\loop.d" "Project\CODE\menu.d" "Project\CODE\touch.d" "Project\USER\scr\isr.d" "Project\USER\scr\main.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-@echo 'Create flash image: Intel-HEX'
	-"E:/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/hex430" -i "msp430g2553.out" -o "msp430g2553.hex" -order MS -romwidth 32
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


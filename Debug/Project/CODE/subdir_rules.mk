################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Project/CODE/%.obj: ../Project/CODE/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="E:/ccs1230/ccs/ccs_base/msp430/include" --include_path="E:/ccs1230/workspace/msp430g2553/Project/USER/scr" --include_path="E:/ccs1230/workspace/msp430g2553/Project/USER/inc" --include_path="E:/ccs1230/workspace/msp430g2553/Project/CODE" --include_path="E:/ccs1230/workspace/msp430g2553/Libraries/libraries" --include_path="E:/ccs1230/workspace/msp430g2553/Libraries/peripheral" --include_path="E:/ccs1230/workspace/msp430g2553/Libraries" --include_path="E:/ccs1230/workspace/msp430g2553" --include_path="E:/ccs1230/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430G2553__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="Project/CODE/$(basename $(<F)).d_raw" --obj_directory="Project/CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/driver/r_ioport/r_ioport.c 

OBJS += \
./synergy/ssp/src/driver/r_ioport/r_ioport.o 

C_DEPS += \
./synergy/ssp/src/driver/r_ioport/r_ioport.d 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/driver/r_ioport/%.o: ../synergy/ssp/src/driver/r_ioport/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\Synergy\e2studio_v6.2.0_ssp_v1.4.0\eclipse\/../\Utilities\\/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\synergy_cfg\ssp_cfg\driver" -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\synergy\ssp\inc" -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\synergy\ssp\inc\bsp" -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\synergy\ssp\inc\driver\api" -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\synergy\ssp\inc\driver\instances" -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\src" -I"C:\Users\rmend\Desktop\Diplomado SW\4.2 Perifericos\ADC\src\synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '



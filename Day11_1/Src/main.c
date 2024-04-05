/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "switch.h"
#include "timer.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
    int duty,count=0;
    SystemInit();
    TimerInit();
    SwitchInit(SWITCH);
    while(1) {
    	while(exti0_flag == 0)
    		;
    	exti0_flag =0;
    	if(count<=12){
    		duty += 10;
    		TIM8->CCR1 = duty;
    		DelayMs(500);
    		count++;
    	}
    	else{
    		duty -= 10;
    		TIM8->CCR1=duty;
    		DelayMs(500);
    		count++;
    	}
    }
	return 0;
}

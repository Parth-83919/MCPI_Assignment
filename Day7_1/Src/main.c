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

#include "led.h"
#include "switch.h"
#include "uart.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
int count ;
int main(void)
{
	SystemInit();
	SwitchInit(SWITCH);
	LedInit(LED_BLUE);
	UartInit(9600);

	char str[20];

	while(1) {
		sprintf(str,"Count=%d\r",count);
		UartPuts(str);
		// wait until switch interrupt generated
		while(exti0_flag == 0)
			;
		// Blink the Led
		LedBlink(LED_BLUE,500);
		exti0_flag = 0;
		count++;
	}
	return 0;
}

/*
 * led.h
 *
 *  Created on: Mar 27, 2024
 *      Author: Nilesh
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f407xx.h"

#define LED_GPIO	GPIOD
#define LED_GPIO_EN	3

#define LED_GREEN	12
#define LED_ORANGE	13
#define LED_RED		14
#define LED_BLUE	15

void LedInit(uint32_t pin);
void LedOn(uint32_t pin);
void LedOff(uint32_t pin);
void LedBlink(uint32_t pin1, uint32_t pin2,  uint32_t pin3, uint32_t pin4);

#endif /* LED_H_ */


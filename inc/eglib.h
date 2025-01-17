#ifndef EGLIB_H
#define EGLIB_H

#include "stm32f103_regs.h"

#include "pwm.h"
#include "gpio.h"

#define GPIO_MODE_INPUT  0x0
#define GPIO_MODE_OUTPUT 0x1



// SysTick Timer
void SysTick_Init(uint32_t system_clock);
void Delay_ms(uint32_t milliseconds);
void SysTick_Handler(void);

// Delay-variable
extern volatile uint32_t tick_count;


void Delay(volatile uint32_t count);


#endif

#ifndef PWM_H
#define PWM_H

#include "stm32f103xb.h"

void PWM_TM3_Init(void);
void PWM_SetDutyCycle(uint16_t duty);

#endif
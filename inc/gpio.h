#ifndef GPIO_H
#define GPIO_H

#include "stm32f103xb.h"


void GPIO_Init(uint32_t gpio_port, uint16_t pin, uint8_t mode);
void PinWrite(uint32_t gpio_port, uint16_t pin, uint8_t state);
uint8_t PinRead(uint32_t gpio_port, uint16_t pin);

#endif
#ifndef STM32F103_REGS_H
#define STM32F103_REGS_H

#include <stdint.h>

// RCC Register
#define RCC_BASE        0x40021000
#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))

// GPIO Register Base Addresses
#define GPIOA_BASE      0x40010800
#define GPIOB_BASE      0x40010C00
#define GPIOC_BASE      0x40011000

// GPIO Register Offsets
#define GPIO_CRL(port)  (*(volatile uint32_t *)(port + 0x00))
#define GPIO_CRH(port)  (*(volatile uint32_t *)(port + 0x04))
#define GPIO_IDR(port)  (*(volatile uint32_t *)(port + 0x08))
#define GPIO_ODR(port)  (*(volatile uint32_t *)(port + 0x0C))
#define GPIO_BSRR(port) (*(volatile uint32_t *)(port + 0x10))
#define GPIO_BRR(port)  (*(volatile uint32_t *)(port + 0x14))

#endif
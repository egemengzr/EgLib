#include "eglib.h"


volatile uint32_t tick_count = 0;

// SysTick ISR
void SysTick_Handler(void) {
    tick_count++;
}

// SysTick_Setup
void SysTick_Init(uint32_t system_clock) {
    // SysTick is 1 ms (1000 Hz)
    uint32_t reload_value = (system_clock / 1000) - 1;
    *(volatile uint32_t *)0xE000E010 = 0;
    *(volatile uint32_t *)0xE000E014 = reload_value;
    *(volatile uint32_t *)0xE000E018 = 0;
    *(volatile uint32_t *)0xE000E010 = 7;
}

// Delay_Func
void Delay_ms(uint32_t milliseconds) {
    uint32_t start_tick = tick_count;
    while ((tick_count - start_tick) < milliseconds);
}

// Delay
void Delay(volatile uint32_t count) {
    while (count--) __asm__("nop");
}

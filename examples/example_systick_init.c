#include "eglib.h"

int main(void) {
    // Initialize SysTick with system clock (8 MHz assumed)
    SysTick_Init(8000000);

    // Enable GPIOC clock
    RCC_APB2ENR |= (1 << 4);

    // Set PC13 as output
    GPIO_Init(GPIOC_BASE, (1 << 13), GPIO_MODE_OUTPUT);

    while (1) {
        // Toggle PC13 using delay
        PinWrite(GPIOC_BASE, (1 << 13), 1);
        Delay_ms(1000);
        PinWrite(GPIOC_BASE, (1 << 13), 0);
        Delay_ms(1000);
    }

    return 0;
}
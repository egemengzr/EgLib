#include "eglib.h"

int main(void) {
    // Enable GPIOA and GPIOC clock
    RCC_APB2ENR |= (1 << 2); // Enable GPIOA
    RCC_APB2ENR |= (1 << 4); // Enable GPIOC

    // Set PA0 as input (pull-up)
    GPIO_Init(GPIOA_BASE, (1 << 0), GPIO_MODE_INPUT);
    GPIO_ODR(GPIOA_BASE) |= (1 << 0); // Activate pull-up

    // Set PC13 as output
    GPIO_Init(GPIOC_BASE, (1 << 13), GPIO_MODE_OUTPUT);

    while (1) {
        if (PinRead(GPIOA_BASE, (1 << 0)) == 0) {
            // Button pressed (LOW)
            PinWrite(GPIOC_BASE, (1 << 13), 0); // LED ON
        } else {
            // Button released (HIGH)
            PinWrite(GPIOC_BASE, (1 << 13), 1); // LED OFF
        }
    }

    return 0;
}
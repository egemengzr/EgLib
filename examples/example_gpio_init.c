
#include "eglib.h"

int main(void) {
    // Enable GPIOC clock
    RCC_APB2ENR |= (1 << 4);

    // Set PC13 as output
    GPIO_Init(GPIOC_BASE, (1 << 13), GPIO_MODE_OUTPUT);

    while (1) {
        // Toggle PC13
        PinWrite(GPIOC_BASE, (1 << 13), 1); // LED ON
        Delay_ms(500);
        PinWrite(GPIOC_BASE, (1 << 13), 0); // LED OFF
        Delay_ms(500);
    }

    return 0;
}
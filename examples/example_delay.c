#include "eglib.h"

int main(void) {
    // Enable GPIOC clock
    RCC_APB2ENR |= (1 << 4);

    // Set PC13 as output
    GPIO_Init(GPIOC_BASE, (1 << 13), GPIO_MODE_OUTPUT);

    while (1) {
        // LED ON
        PinWrite(GPIOC_BASE, (1 << 13), 1);
        Delay_ms(2000);

        // LED OFF
        PinWrite(GPIOC_BASE, (1 << 13), 0);
        Delay_ms(2000);
    }

    return 0;
}
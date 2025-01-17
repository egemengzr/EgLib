#include "eglib.h"



#define GPIO_MODE_INPUT  0x0
#define GPIO_MODE_OUTPUT 0x1

// PinWrite: Set GPIO pin as HIGH or LOW
void PinWrite(uint32_t gpio_port, uint16_t pin, uint8_t state) {
    if (state) {
        GPIO_BSRR(gpio_port) = pin; // Set the Pin
    } else {
        GPIO_BRR(gpio_port) = pin; // Reset the Pin
    }
}

// PinRead: Read the GPIO Pin
uint8_t PinRead(uint32_t gpio_port, uint16_t pin) {
    return (GPIO_IDR(gpio_port) & pin) ? 1 : 0;
}


void GPIO_Init(uint32_t gpio_port, uint16_t pin, uint8_t mode) {
    uint8_t pin_pos = 0;

    // Hangi pin oldugu hesaplanir (ör. 1 << 13 icin pin_pos = 13)
    while (pin >>= 1) pin_pos++;

    // Pin dusuk (CRL) veya yuksek (CRH) kisminda mi?
    if (pin_pos < 8) {
        // CRL kismini düzenle
        GPIO_CRL(gpio_port) &= ~(0xF << (pin_pos * 4)); // Temizle
        if (mode == GPIO_MODE_INPUT) {
            GPIO_CRL(gpio_port) |= (0x8 << (pin_pos * 4)); // Giris modu (pull-up/pull-down)
        } else {
            GPIO_CRL(gpio_port) |= (0x2 << (pin_pos * 4)); // Cikis modu
        }
    } else {
        // CRH kısmını düzenle
        pin_pos -= 8;
        GPIO_CRH(gpio_port) &= ~(0xF << (pin_pos * 4)); // Temizle
        if (mode == GPIO_MODE_INPUT) {
            GPIO_CRH(gpio_port) |= (0x8 << (pin_pos * 4)); // Giris modu (pull-up/pull-down)
        } else {
            GPIO_CRH(gpio_port) |= (0x2 << (pin_pos * 4)); // Cikis modu
        }
    }
}
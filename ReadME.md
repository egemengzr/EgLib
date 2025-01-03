# Egemen Embedded Library  
*A lightweight and register-level embedded library for STM32 and ESP32*  

## Introduction  
This library was initially developed for the **STM32F10x series**, but it is being expanded to support other microcontrollers like **ESP32**. It is designed to be a minimal and efficient **register-level** library, avoiding the overhead of larger HAL or SPL frameworks.  

Since this is a personal project, the library is **still in development**, and there might be **some bugs**. I am actively working on improvements in my free time. Contributions and suggestions are always welcome!  

---

## Features  
✅ **GPIO Control** – Read, write, and configure GPIO pins at the register level.  
✅ **Basic Delay Function** – Implemented using **SysTick** for STM32 and **FreeRTOS vTaskDelay** for ESP32.  
✅ **Multi-Platform Support** – Easily configurable for different MCUs.  
✅ **Minimalistic & Efficient** – No HAL, no SPL, just pure low-level control.  

---

## Supported Microcontrollers  
- ✅ STM32F103 (tested)  
- ⏳ STM32F303 (planned)  
- ✅ ESP32 (partially implemented)  

---

## Getting Started  

### 1. Clone the Repository  
```sh
git clone https://github.com/yourusername/egemen-lib.git
```
---

### 2. Configure Your Target MCU
Edit the config.h file and select your target microcontroller:

```c
#define STM32F103
//#define ESP32
```
---

### 3. Include in Your Project

Add the following to your main C file:

```c
#include "egemen.h"

int main(void) {
    GPIO_Init(GPIOA_BASE, (1 << 5), GPIO_MODE_OUTPUT);
    
    while (1) {
        PinWrite(GPIOA_BASE, (1 << 5), 1); // LED ON
        Delay(500);
        PinWrite(GPIOA_BASE, (1 << 5), 0); // LED OFF
        Delay(500);
    }
}
```

---

### Planned Features
🔹 SPI & I2C Communication
🔹 UART Implementation
🔹 PWM & ADC Functions
🔹 More STM32 & ESP32 Support

### Contributing

If you find any bugs or have feature requests, feel free to open an issue or a pull request on GitHub! 🚀

---

### License

This project is licensed under the MIT License – feel free to use, modify, and share!
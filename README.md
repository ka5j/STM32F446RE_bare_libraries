# STM32 Bare-Metal GPIO & SysTick Driver Library

Author: **(ka5j)**  
Board: **STM32F446RE Nucleo**  
Language: **C (Bare-metal)**  
License: **MIT**

---

## Overview

This is a **bare-metal driver library** written from scratch for the **STM32F446RE** microcontroller. It provides **GPIO** and **SysTick timer** functionality without relying on STM32 HAL or CMSIS driver layers.

> This project demonstrates my embedded systems expertise in writing production-grade, lightweight, hardware-level drivers for ARM Cortex-M4-based microcontrollers.

---

## Features

### GPIO Driver (`bare_gpio.h/.c`)
- Pin initialization with mode, output type, speed, pull-up/down
- Write, read, and toggle pin values
- Type-safe API using custom enums
- No runtime heap or HAL dependencies
- Inline optimizations and strict type checks

### SysTick Driver (`bare_systick.h/.c`)
- Timer initialization with clock source and interrupt enable flags
- Runtime reload update
- Suitable for implementing delays or periodic task triggers

---

## Why This Project Matters

| Skill Demonstrated       | Description |
|--------------------------|-------------|
| **Bare-metal C**         | No dependencies on HAL or RTOS. Registers accessed directly via bitwise ops. |
| **Hardware Abstraction** | Enum-based APIs improve safety, readability, and portability. |
| **Register-level control** | Custom `stm32f446re_registers.h` built to control peripherals manually. |
| **Maintainable Codebase** | Designed to be clean, documented, and scalable. |

---

### Prerequisites

- STM32F446RE Nucleo board
- STM32CubeIDE **or** bare-metal toolchain (e.g., arm-none-eabi-gcc + OpenOCD)
- Flash/debug setup (ST-Link, J-Link, etc.)

### Clone the Repository

```bash
git clone https://github.com/ka5j/STM32F446RE_BARE_LIBRARIES
cd STM32F446RE_BARE_LIBRARIES
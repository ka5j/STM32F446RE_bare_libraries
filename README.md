# STM32F446RE Bare-Metal Register Library

> A low-level, fully documented STM32F446RE peripheral register mapping library — ideal for learning embedded systems, writing custom drivers, and building projects without relying on HAL/LL abstractions.

---

## Overview

This project contains handcrafted, memory-mapped register definitions for the STM32F446RE microcontroller, built entirely from scratch using the STM32 reference manual. It is designed for bare-metal embedded development and educational purposes.

No CMSIS. No HAL. Just pure control of the hardware.

## Features

- Clean and complete register mappings for:
  - RCC
  - GPIOA–GPIOH
  - SysTick
  - NVIC
  - AHB/APB bus mappings
- Accurate reserved memory regions
- Fully commented with bitfields and register layouts
- Designed for real-world bare-metal STM32 projects
- Lightweight and header-only

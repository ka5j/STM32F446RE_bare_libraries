/*******************************************************************************************
 * @file    bare_gpio.h
 * @author  ka5j
 * @brief   Bare-metal GPIO driver for STM32F446RE
 * @version 1.0
 * @date    2025-04-28
 *
 * @note    Provides high-level GPIO functionality without HAL.
 *******************************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

#include "device_registers.h"
#include <stdint.h>

#define GPIO_PIN_HIGH 0x01
#define GPIO_PIN_LOW 0x00

typedef enum{
    GPIO_MODE_INPUT = 0x00,
    GPIO_MODE_OUTPUT = 0x01,
    GPIO_MODE_AF = 0x02,
    GPIO_MODE_ANALOG = 0x03
}GPIO_Mode_t;

typedef enum {
    GPIO_OTYPE_PP = 0x00U, // Push-Pull
    GPIO_OTYPE_OD = 0x01U  // Open-Drain
}GPIO_OType_t;

typedef enum {
    GPIO_SPEED_LOW    = 0x00,
    GPIO_SPEED_MEDIUM = 0x01,
    GPIO_SPEED_FAST   = 0x02,
    GPIO_SPEED_HIGH   = 0x03
}GPIO_Speed_t;

typedef enum {
    GPIO_NOPULL = 0x00U,
    GPIO_PULLUP = 0x01U,
    GPIO_PULLDOWN = 0x02U
}GPIO_Pull_t;

void bare_gpio_init(GPIO_TypeDef *GPIOx, uint8_t pin, GPIO_Mode_t mode,
    GPIO_OType_t otype, GPIO_Speed_t speed, GPIO_Pull_t pull);

void bare_gpio_write(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t state);

uint8_t bare_gpio_read(GPIO_TypeDef *GPIOx, uint8_t pin);

void bare_gpio_toggle(GPIO_TypeDef *GPIOx, uint8_t pin);

#endif /* GPIO_H_ */
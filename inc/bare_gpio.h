/*******************************************************************************************
 * @file    bare_gpio.h
 * @author  ka5j
 * @brief   Bare-metal GPIO driver for STM32F446RE
 * @version 1.0
 * @date    2025-04-28
 *
 * @note    Provides high-level GPIO functionality without relying on STM32 HAL drivers.
 *******************************************************************************************/

#ifndef BARE_GPIO_H_
#define BARE_GPIO_H_

#include "device_registers.h"  // Include low-level register definitions
#include <stdint.h>            // Include standard integer types

/*******************************************************************************************
 * GPIO Pin State Definitions
 *******************************************************************************************/
#define GPIO_PIN_HIGH   0x01U
#define GPIO_PIN_LOW    0x00U

/*******************************************************************************************
 * GPIO Configuration Enumerations
 *******************************************************************************************/

/**
 * @brief GPIO Pin Modes
 */
typedef enum {
    GPIO_MODE_INPUT  = 0x00U, /*!< Input Floating */
    GPIO_MODE_OUTPUT = 0x01U, /*!< Output Push-Pull/Open-Drain */
    GPIO_MODE_AF     = 0x02U, /*!< Alternate Function */
    GPIO_MODE_ANALOG = 0x03U  /*!< Analog Mode */
} GPIO_Mode_t;

/**
 * @brief GPIO Output Types
 */
typedef enum {
    GPIO_OTYPE_PP = 0x00U, /*!< Push-Pull */
    GPIO_OTYPE_OD = 0x01U  /*!< Open-Drain */
} GPIO_OType_t;

/**
 * @brief GPIO Output Speeds
 */
typedef enum {
    GPIO_SPEED_LOW    = 0x00U, /*!< Low Speed */
    GPIO_SPEED_MEDIUM = 0x01U, /*!< Medium Speed */
    GPIO_SPEED_FAST   = 0x02U, /*!< Fast Speed */
    GPIO_SPEED_HIGH   = 0x03U  /*!< High Speed */
} GPIO_Speed_t;

/**
 * @brief GPIO Pull-up/Pull-down Configurations
 */
typedef enum {
    GPIO_NOPULL = 0x00U, /*!< No Pull-up or Pull-down */
    GPIO_PULLUP = 0x01U, /*!< Pull-up Enabled */
    GPIO_PULLDOWN = 0x02U /*!< Pull-down Enabled */
} GPIO_Pull_t;

/*******************************************************************************************
 * API Function Prototypes
 *******************************************************************************************/

/**
 * @brief Initialize a GPIO pin with specified configurations
 * 
 * @param GPIOx   Pointer to GPIO peripheral (e.g., GPIOA, GPIOB, etc.)
 * @param pin     GPIO pin number (0-15)
 * @param mode    Mode of the GPIO pin
 * @param otype   Output type configuration
 * @param speed   Output speed configuration
 * @param pull    Pull-up/Pull-down configuration
 */
void bare_gpio_init(GPIO_TypeDef *GPIOx, uint8_t pin, GPIO_Mode_t mode,
                    GPIO_OType_t otype, GPIO_Speed_t speed, GPIO_Pull_t pull);

/**
 * @brief Write a HIGH or LOW value to a GPIO pin
 * 
 * @param GPIOx   Pointer to GPIO peripheral
 * @param pin     GPIO pin number
 * @param state   GPIO_PIN_HIGH or GPIO_PIN_LOW
 */
void bare_gpio_write(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t state);

/**
 * @brief Read the current state of a GPIO pin
 * 
 * @param GPIOx   Pointer to GPIO peripheral
 * @param pin     GPIO pin number
 * @return uint8_t GPIO_PIN_HIGH or GPIO_PIN_LOW
 */
uint8_t bare_gpio_read(GPIO_TypeDef *GPIOx, uint8_t pin);

/**
 * @brief Toggle the current state of a GPIO pin
 * 
 * @param GPIOx   Pointer to GPIO peripheral
 * @param pin     GPIO pin number
 */
void bare_gpio_toggle(GPIO_TypeDef *GPIOx, uint8_t pin);

#endif /* BARE_GPIO_H_ */

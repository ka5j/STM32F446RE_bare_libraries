/*******************************************************************************************
 * @file    gpio_registers.h
 * @author  ka5j
 * @brief   STM32F446RE GPIO Device Memory-Mapped Register Definitions (Bare Metal)
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Only memory-mapped register definitions for GPIO modules.
 *          This file assumes a 32-bit embedded platform and no CMSIS dependency.
 *******************************************************************************************/

#ifndef GPIO_REGISTERS_H_
#define GPIO_REGISTERS_H_

#include <stdint.h>
#include "stm32f446re_addresses.h"

/*******************************************************************************************
 * GPIO Base Addresses
 *******************************************************************************************/
#define GPIOA_BASE (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE (AHB1PERIPH_BASE + 0x1C00UL)

/*******************************************************************************************
 * GPIO Register Definition
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t MODER;     /*!< GPIO port mode register */
    volatile uint32_t OTYPER;    /*!< GPIO port output type register */
    volatile uint32_t OSPEEDR;   /*!< GPIO port output speed register */
    volatile uint32_t PUPDR;     /*!< GPIO port pull-up/pull-down register */
    const volatile uint32_t IDR; /*!< GPIO port input data register (read-only) */
    volatile uint32_t ODR;       /*!< GPIO port output data register */
    volatile uint32_t BSRR;      /*!< GPIO port bit set/reset register */
    volatile uint32_t LCKR;      /*!< GPIO port configuration lock register */
    volatile uint32_t AFRL;      /*!< GPIO alternate function low register */
    volatile uint32_t AFRH;      /*!< GPIO alternate function high register */
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)

#endif
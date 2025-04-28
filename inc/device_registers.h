/*******************************************************************************************
 * @file    device_registers.h
 * @author  ka5j
 * @brief   STM32F446RE Device Memory Mapped Register Definitions
 * @version 1.0
 * @date    2025-04-28
 *
 * @note    This file defines structures and base addresses for STM32F446RE peripherals.
 *          Only memory-mapped register definitions. No function code here.
 *******************************************************************************************/

#ifndef DEVICE_REGISTERS_H_
#define DEVICE_REGISTERS_H_

#include <stdint.h> // Needed for uint32_t, uint8_t types

/*******************************************************************************************
 * Peripheral Bus Base Addresses
 *******************************************************************************************/
#define APB1PERIPH_BASE       0x40000000U
#define APB2PERIPH_BASE       0x40010000U
#define AHB1PERIPH_BASE       0x40020000U
#define AHB2PERIPH_BASE       0x50000000U
#define AHB3PERIPH_BASE       0x60000000U
#define CORTEX_M4_PERIPH_BASE 0xE0000000U

/*******************************************************************************************
 * Cortex-M4 Specific Peripherals
 *******************************************************************************************/
#define SYSTICK_BASE        (CORTEX_M4_PERIPH_BASE + 0xE010U)
#define NVIC_BASE           (CORTEX_M4_PERIPH_BASE + 0xE100U)

/*******************************************************************************************
 * AHB1 Peripherals
 *******************************************************************************************/
#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800U)

/*******************************************************************************************
 * APB2 Peripherals
 *******************************************************************************************/
#define EXTI_BASE           (APB2PERIPH_BASE + 0x3C00U)
#define SYSCFG_BASE         (APB2PERIPH_BASE + 0x3800U)

/*******************************************************************************************
 * GPIO Base Addresses
 *******************************************************************************************/
#define GPIOA_BASE          (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE          (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE          (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE          (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE          (AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASE          (AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASE          (AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE          (AHB1PERIPH_BASE + 0x1C00U)

/*******************************************************************************************
 * GPIO Peripheral Definitions
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00 */
    volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04 */
    volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08 */
    volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C */
    volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10 */
    volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14 */
    volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18 */
    volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C */
    volatile uint32_t AFRL;     /*!< GPIO alternate function low register,  Address offset: 0x20 */
    volatile uint32_t AFRH;     /*!< GPIO alternate function high register, Address offset: 0x24 */
} GPIO_TypeDef;

/*******************************************************************************************
 * GPIO Peripheral Instances
 *******************************************************************************************/
#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF   ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG   ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH   ((GPIO_TypeDef *) GPIOH_BASE)

/*******************************************************************************************
 * Timer Base Addresses (APB1 timers)
 *******************************************************************************************/
#define TIM2_BASE           (APB1PERIPH_BASE + 0x0000U)
#define TIM3_BASE           (APB1PERIPH_BASE + 0x0400U)
#define TIM4_BASE           (APB1PERIPH_BASE + 0x0800U)
#define TIM5_BASE           (APB1PERIPH_BASE + 0x0C00U)

#endif /* DEVICE_REGISTERS_H_ */

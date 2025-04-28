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

#include <stdint.h>

//Base addresss for peripheral buses
#define APB1PERPH_BASE 0x40000000
#define APB2PERPH_BASE 0x40010000
#define AHB1PERPH_BASE 0x40020000
#define AHB2PERPH_BASE 0x50000000
#define AHB3PERPH_BASE 0x60000000
#define M4PERPH_BASE   0xE0000000

//SysTick base address
#define SYSTICK_BASE (M4PERPH_BASE + 0xE010)

//NVIC base address
#define NVIC_BASE (M4PERPH_BASE + 0xE100)

//RCC base address
#define RCC_BASE (AHB1PERPH_BASE + 0x3800)

//EXTI Base address
#define EXTI_BASE (APB2PERPH_BASE + 0x3C00)

//SYSCFG base address
#define SYSCFG_BASE (APB2PERPH_BASE + 0x3800)

//GPIOx base addresses
#define GPIOA_BASE (AHB1PERPH_BASE + 0x0000)
#define GPIOB_BASE (AHB1PERPH_BASE + 0x0400)
#define GPIOC_BASE (AHB1PERPH_BASE + 0x0800)
#define GPIOD_BASE (AHB1PERPH_BASE + 0x0C00)
#define GPIOE_BASE (AHB1PERPH_BASE + 0x1000)
#define GPIOF_BASE (AHB1PERPH_BASE + 0x1400)
#define GPIOG_BASE (AHB1PERPH_BASE + 0x1800)
#define GPIOH_BASE (AHB1PERPH_BASE + 0x1C00)

//Define gpio ports
#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF   ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG   ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH   ((GPIO_TypeDef *) GPIOH_BASE)

typedef struct {
    volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00 */
    volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04 */
    volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08 */
    volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C */
    volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10 */
    volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14 */
    volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18 */
    volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C */
    volatile uint32_t AFRH, AFRL;   /*!< GPIO alternate function registers,     AFR[0] -> 0x20, AFR[1] -> 0x24 */
} GPIO_TypeDef;

//Timer base addresses
#define TIM2_BASE (APB1PERPH_BASE + 0x0000)
#define TIM3_BASE (APB1PERPH_BASE + 0x0400)
#define TIM4_BASE (APB1PERPH_BASE + 0x0800)
#define TIM5_BASE (APB1PERPH_BASE + 0x0C00)

typedef volatile struct{
    uint32_t MODER;    // GPIO Mode Register
    uint32_t OTYPER;   // GPIO Output Type Register
    uint32_t OSPEEDR;  // GPIO Output Speed Register
    uint32_t PUPDR;    // GPIO Pull-up/Pull-down Register
    uint32_t IDR;      // GPIO Input Data Register
    uint32_t ODR;      // GPIO Output Data Register
    uint32_t BSRR;     // GPIO Bit Set/Reset Register
    uint32_t LCKR;     // GPIO Lock Register
    uint32_t AFRL, AFRH;   // GPIO Alternate Function Registers
}GPIO_RegDef_t;

#endif /* BOARD_CONFIG_H_ */
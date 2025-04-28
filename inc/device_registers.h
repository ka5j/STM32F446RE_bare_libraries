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
 * RCC Peripheral Definitions
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t CR;             /*!< RCC clock control register,                         Address offset: 0x00 */
    volatile uint32_t PLLCFGR;        /*!< RCC PLL configuration register,                     Address offset: 0x04 */
    volatile uint32_t CFGR;           /*!< RCC clock configuration register,                   Address offset: 0x08 */
    volatile uint32_t CIR;            /*!< RCC clock interrupt register,                       Address offset: 0x0C */
    volatile uint32_t AHB1RSTR;       /*!< RCC AHB1 peripheral reset register,                  Address offset: 0x10 */
    volatile uint32_t AHB2RSTR;       /*!< RCC AHB2 peripheral reset register,                  Address offset: 0x14 */
    volatile uint32_t AHB3RSTR;       /*!< RCC AHB3 peripheral reset register,                  Address offset: 0x18 */
    uint32_t RESERVED0;               /*!< Reserved,                                            Address offset: 0x1C */
    volatile uint32_t APB1RSTR;       /*!< RCC APB1 peripheral reset register,                  Address offset: 0x20 */
    volatile uint32_t APB2RSTR;       /*!< RCC APB2 peripheral reset register,                  Address offset: 0x24 */
    uint32_t RESERVED1;               /*!< Reserved,                                            Address offset: 0x28 */
    uint32_t RESERVED2;               /*!< Reserved,                                            Address offset: 0x2C */
    volatile uint32_t AHB1ENR;        /*!< RCC AHB1 peripheral clock enable register,           Address offset: 0x30 */
    volatile uint32_t AHB2ENR;        /*!< RCC AHB2 peripheral clock enable register,           Address offset: 0x34 */
    volatile uint32_t AHB3ENR;        /*!< RCC AHB3 peripheral clock enable register,           Address offset: 0x38 */
    uint32_t RESERVED3;               /*!< Reserved,                                            Address offset: 0x3C */
    volatile uint32_t APB1ENR;        /*!< RCC APB1 peripheral clock enable register,           Address offset: 0x40 */
    volatile uint32_t APB2ENR;        /*!< RCC APB2 peripheral clock enable register,           Address offset: 0x44 */
    uint32_t RESERVED4;               /*!< Reserved,                                            Address offset: 0x48 */
    uint32_t RESERVED5;               /*!< Reserved,                                            Address offset: 0x4C */
    volatile uint32_t AHB1LPENR;      /*!< RCC AHB1 peripheral clock enable in low power mode,  Address offset: 0x50 */
    volatile uint32_t AHB2LPENR;      /*!< RCC AHB2 peripheral clock enable in low power mode,  Address offset: 0x54 */
    volatile uint32_t AHB3LPENR;      /*!< RCC AHB3 peripheral clock enable in low power mode,  Address offset: 0x58 */
    uint32_t RESERVED6;               /*!< Reserved,                                            Address offset: 0x5C */
    volatile uint32_t APB1LPENR;      /*!< RCC APB1 peripheral clock enable in low power mode,  Address offset: 0x60 */
    volatile uint32_t APB2LPENR;      /*!< RCC APB2 peripheral clock enable in low power mode,  Address offset: 0x64 */
    uint32_t RESERVED7;               /*!< Reserved,                                            Address offset: 0x68 */
    uint32_t RESERVED8;               /*!< Reserved,                                            Address offset: 0x6C */
    volatile uint32_t BDCR;           /*!< RCC Backup domain control register,                  Address offset: 0x70 */
    volatile uint32_t CSR;            /*!< RCC clock control & status register,                 Address offset: 0x74 */
    uint32_t RESERVED9;               /*!< Reserved,                                            Address offset: 0x78 */
    uint32_t RESERVED10;              /*!< Reserved,                                            Address offset: 0x7C */
    volatile uint32_t SSCGR;          /*!< RCC spread spectrum clock generation register,       Address offset: 0x80 */
    volatile uint32_t PLLI2SCFGR;     /*!< RCC PLLI2S configuration register,                   Address offset: 0x84 */
    volatile uint32_t PLLSAICFGR;     /*!< RCC PLLSAI configuration register,                   Address offset: 0x88 */
    volatile uint32_t DCKCFGR;        /*!< RCC dedicated clocks configuration register,         Address offset: 0x8C */
    volatile uint32_t CKGATENR;       /*!< RCC clocks gated enable register,                    Address offset: 0x90 */
    volatile uint32_t DCKCFGR2;       /*!< RCC dedicated clocks configuration register 2,       Address offset: 0x94 */
} RCC_TypeDef;

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

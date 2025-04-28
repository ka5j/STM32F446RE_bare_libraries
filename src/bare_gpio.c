/*******************************************************************************************
 * @file    device_registers.h
 * @author  ka5j
 * @brief   STM32F446RE Device Memory-Mapped Register Definitions
 * @version 1.0
 * @date    2025-04-28
 *
 * @note    This file defines structures and base addresses for STM32F446RE peripherals.
 *          Only memory-mapped register definitions are included. No function implementations.
 *******************************************************************************************/

#ifndef DEVICE_REGISTERS_H_
#define DEVICE_REGISTERS_H_

#include <stdint.h> // Standard integer types

/*******************************************************************************************
 * Cortex-M4 Core Peripheral Base Addresses
 *******************************************************************************************/
#define CORTEX_M4_PERIPH_BASE    (0xE0000000U)
#define SYSTICK_BASE             (CORTEX_M4_PERIPH_BASE + 0xE010U)
#define NVIC_BASE                (CORTEX_M4_PERIPH_BASE + 0xE100U)

/*******************************************************************************************
 * Bus Peripheral Base Addresses
 *******************************************************************************************/
#define APB1PERIPH_BASE          (0x40000000U)
#define APB2PERIPH_BASE          (0x40010000U)
#define AHB1PERIPH_BASE          (0x40020000U)
#define AHB2PERIPH_BASE          (0x50000000U)
#define AHB3PERIPH_BASE          (0x60000000U)

/*******************************************************************************************
 * SysTick Register Definition
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t CSR;       /*!< SysTick Control and Status Register */
    volatile uint32_t RVR;       /*!< SysTick Reload Value Register */
    volatile uint32_t CVR;       /*!< SysTick Current Value Register */
    volatile uint32_t CALIB;     /*!< SysTick Calibration Register */
} SysTick_TypeDef;

/*******************************************************************************************
 * NVIC Register Definition
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t ISER[8];      /*!< Interrupt Set-Enable Registers,           Address offset: 0x000 */
    uint32_t RESERVED0[24];         /*!< Reserved,                                 Address offset: 0x020-0x07C */
    volatile uint32_t ICER[8];      /*!< Interrupt Clear-Enable Registers,         Address offset: 0x080 */
    uint32_t RESERVED1[24];         /*!< Reserved,                                 Address offset: 0x0A0-0x0FC */
    volatile uint32_t ISPR[8];      /*!< Interrupt Set-Pending Registers,          Address offset: 0x100 */
    uint32_t RESERVED2[24];         /*!< Reserved,                                 Address offset: 0x120-0x17C */
    volatile uint32_t ICPR[8];      /*!< Interrupt Clear-Pending Registers,        Address offset: 0x180 */
    uint32_t RESERVED3[24];         /*!< Reserved,                                 Address offset: 0x1A0-0x1FC */
    volatile uint32_t IABR[8];      /*!< Interrupt Active Bit Registers,           Address offset: 0x200 */
    uint32_t RESERVED4[56];         /*!< Reserved,                                 Address offset: 0x220-0x2FC */
    volatile uint8_t IPR[240];      /*!< Interrupt Priority Registers,             Address offset: 0x300 */
    uint32_t RESERVED5[644];        /*!< Reserved for future expansion */
    volatile uint32_t STIR;         /*!< Software Trigger Interrupt Register,      Address offset: 0xE00 */
} NVIC_TypeDef;

/*******************************************************************************************
 * Core Peripheral Instances
 *******************************************************************************************/
#define SYSTICK    ((SysTick_TypeDef *) SYSTICK_BASE)
#define NVIC       ((NVIC_TypeDef *) NVIC_BASE)

/*******************************************************************************************
 * RCC (Reset and Clock Control) Base Address
 *******************************************************************************************/
#define RCC_BASE                (AHB1PERIPH_BASE + 0x3800U)

/*******************************************************************************************
 * RCC Register Definition
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1;
    uint32_t RESERVED2;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t RESERVED3;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t RESERVED4;
    uint32_t RESERVED5;
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    uint32_t RESERVED6;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t RESERVED7;
    uint32_t RESERVED8;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t RESERVED9;
    uint32_t RESERVED10;
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t PLLSAICFGR;
    volatile uint32_t DCKCFGR;
    volatile uint32_t CKGATENR;
    volatile uint32_t DCKCFGR2;
} RCC_TypeDef;

/*******************************************************************************************
 * RCC Instance
 *******************************************************************************************/
#define RCC     ((RCC_TypeDef *) RCC_BASE)

/*******************************************************************************************
 * GPIO Base Addresses
 *******************************************************************************************/
#define GPIOA_BASE              (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE              (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE              (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE              (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE              (AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASE              (AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASE              (AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE              (AHB1PERIPH_BASE + 0x1C00U)

/*******************************************************************************************
 * GPIO Register Definition
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t MODER;     /*!< GPIO port mode register */
    volatile uint32_t OTYPER;    /*!< GPIO port output type register */
    volatile uint32_t OSPEEDR;   /*!< GPIO port output speed register */
    volatile uint32_t PUPDR;     /*!< GPIO port pull-up/pull-down register */
    volatile uint32_t IDR;       /*!< GPIO port input data register */
    volatile uint32_t ODR;       /*!< GPIO port output data register */
    volatile uint32_t BSRR;      /*!< GPIO port bit set/reset register */
    volatile uint32_t LCKR;      /*!< GPIO port configuration lock register */
    volatile uint32_t AFRL;      /*!< GPIO alternate function low register */
    volatile uint32_t AFRH;      /*!< GPIO alternate function high register */
} GPIO_TypeDef;

/*******************************************************************************************
 * GPIO Instances
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
#define TIM2_BASE               (APB1PERIPH_BASE + 0x0000U)
#define TIM3_BASE               (APB1PERIPH_BASE + 0x0400U)
#define TIM4_BASE               (APB1PERIPH_BASE + 0x0800U)
#define TIM5_BASE               (APB1PERIPH_BASE + 0x0C00U)

#endif /* DEVICE_REGISTERS_H_ */

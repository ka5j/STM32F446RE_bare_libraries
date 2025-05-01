/*******************************************************************************************
 * @file    stm32f446re_registers.h
 * @author  ka5j
 * @brief   STM32F446RE Device Memory-Mapped Register Definitions (Bare Metal)
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Only memory-mapped register definitions for core and peripheral modules.
 *          This file assumes a 32-bit embedded platform and no CMSIS dependency.
 *******************************************************************************************/

#ifndef STM32F446RE_REGISTERS_H_
#define STM32F446RE_REGISTERS_H_

#include <stdint.h>

/*******************************************************************************************
 * Platform and Device Validation
 *******************************************************************************************/
#if UINT32_MAX != 0xFFFFFFFF
#error "This header requires a 32-bit platform (uint32_t must be 4 bytes)."
#endif

/*******************************************************************************************
 * Cortex-M4 Core Peripheral Base Addresses
 *******************************************************************************************/
#define CORTEX_M4_PERIPH_BASE     (0xE0000000UL)
#define SYSTICK_BASE              (CORTEX_M4_PERIPH_BASE + 0xE010UL)
#define NVIC_BASE                 (CORTEX_M4_PERIPH_BASE + 0xE100UL)

/*******************************************************************************************
 * Bus Peripheral Base Addresses
 *******************************************************************************************/
#define APB1PERIPH_BASE           (0x40000000UL)
#define APB2PERIPH_BASE           (0x40010000UL)
#define AHB1PERIPH_BASE           (0x40020000UL)
#define AHB2PERIPH_BASE           (0x50000000UL)
#define AHB3PERIPH_BASE           (0x60000000UL)

/*******************************************************************************************
 * SysTick Register Definition
 *******************************************************************************************/
typedef struct {
    volatile uint32_t CSR;        /*!< Control and Status Register */
    volatile uint32_t RVR;        /*!< Reload Value Register */
    volatile uint32_t CVR;        /*!< Current Value Register */
    const volatile uint32_t CALIB;/*!< Calibration Register (read-only) */
} SysTick_TypeDef;

#define SYSTICK                   ((SysTick_TypeDef *) SYSTICK_BASE)

/*******************************************************************************************
 * NVIC Register Definition
 *******************************************************************************************/
typedef struct {
    volatile uint32_t ISER[8];    /*!< Interrupt Set-Enable Registers */
    uint32_t RESERVED0[24];       /*!< Reserved: 0x020 - 0x07C */
    volatile uint32_t ICER[8];    /*!< Interrupt Clear-Enable Registers */
    uint32_t RESERVED1[24];       /*!< Reserved: 0x0A0 - 0x0FC */
    volatile uint32_t ISPR[8];    /*!< Interrupt Set-Pending Registers */
    uint32_t RESERVED2[24];       /*!< Reserved: 0x120 - 0x17C */
    volatile uint32_t ICPR[8];    /*!< Interrupt Clear-Pending Registers */
    uint32_t RESERVED3[24];       /*!< Reserved: 0x1A0 - 0x1FC */
    volatile uint32_t IABR[8];    /*!< Interrupt Active Bit Registers */
    uint32_t RESERVED4[56];       /*!< Reserved: 0x220 - 0x2FC */
    volatile uint8_t IPR[240];    /*!< Interrupt Priority Registers */
    uint32_t RESERVED5[644];      /*!< Reserved: 0x3F0 - 0xE00 (magic: (0xE00 - 0x3F0) / 4 = 644) */
    volatile uint32_t STIR;       /*!< Software Trigger Interrupt Register */
} NVIC_TypeDef;

#define NVIC                      ((NVIC_TypeDef *) NVIC_BASE)

/*******************************************************************************************
 * RCC (Reset and Clock Control)
 *******************************************************************************************/
#define RCC_BASE                  (AHB1PERIPH_BASE + 0x3800UL)

typedef struct {
    volatile uint32_t CR;         /*!< Clock control register */
    volatile uint32_t PLLCFGR;    /*!< PLL configuration register */
    volatile uint32_t CFGR;       /*!< Clock configuration register */
    volatile uint32_t CIR;        /*!< Clock interrupt register */
    volatile uint32_t AHB1RSTR;   /*!< AHB1 peripheral reset register */
    volatile uint32_t AHB2RSTR;   /*!< AHB2 peripheral reset register */
    volatile uint32_t AHB3RSTR;   /*!< AHB3 peripheral reset register */
    uint32_t RESERVED0;           /*!< Reserved: 0x1C */
    volatile uint32_t APB1RSTR;   /*!< APB1 peripheral reset register */
    volatile uint32_t APB2RSTR;   /*!< APB2 peripheral reset register */
    uint32_t RESERVED1;           /*!< Reserved: 0x28 */
    uint32_t RESERVED2;           /*!< Reserved: 0x2C */
    volatile uint32_t AHB1ENR;    /*!< AHB1 peripheral clock enable register */
    volatile uint32_t AHB2ENR;    /*!< AHB2 peripheral clock enable register */
    volatile uint32_t AHB3ENR;    /*!< AHB3 peripheral clock enable register */
    uint32_t RESERVED3;           /*!< Reserved: 0x3C */
    volatile uint32_t APB1ENR;    /*!< APB1 peripheral clock enable register */
    volatile uint32_t APB2ENR;    /*!< APB2 peripheral clock enable register */
    uint32_t RESERVED4;           /*!< Reserved: 0x48 */
    uint32_t RESERVED5;           /*!< Reserved: 0x4C */
    volatile uint32_t AHB1LPENR;  /*!< AHB1 low power enable register */
    volatile uint32_t AHB2LPENR;  /*!< AHB2 low power enable register */
    volatile uint32_t AHB3LPENR;  /*!< AHB3 low power enable register */
    uint32_t RESERVED6;           /*!< Reserved: 0x5C */
    volatile uint32_t APB1LPENR;  /*!< APB1 low power enable register */
    volatile uint32_t APB2LPENR;  /*!< APB2 low power enable register */
    uint32_t RESERVED7;           /*!< Reserved: 0x68 */
    uint32_t RESERVED8;           /*!< Reserved: 0x6C */
    volatile uint32_t BDCR;       /*!< Backup domain control register */
    volatile uint32_t CSR;        /*!< Clock control & status register */
    uint32_t RESERVED9;           /*!< Reserved: 0x78 */
    uint32_t RESERVED10;          /*!< Reserved: 0x7C */
    volatile uint32_t SSCGR;      /*!< Spread spectrum clock generation register */
    volatile uint32_t PLLI2SCFGR; /*!< PLLI2S configuration register */
    volatile uint32_t PLLSAICFGR; /*!< PLLSAI configuration register */
    volatile uint32_t DCKCFGR;    /*!< Dedicated clocks configuration register */
    volatile uint32_t CKGATENR;   /*!< Clocks gated enable register */
    volatile uint32_t DCKCFGR2;   /*!< Dedicated clocks configuration register 2 */
} RCC_TypeDef;

#define RCC                       ((RCC_TypeDef *) RCC_BASE)

/*******************************************************************************************
 * GPIO Base Addresses
 *******************************************************************************************/
#define GPIOA_BASE                (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE                (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE                (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE                (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE                (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE                (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE                (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE                (AHB1PERIPH_BASE + 0x1C00UL)

/*******************************************************************************************
 * GPIO Register Definition
 *******************************************************************************************/
typedef struct {
    volatile uint32_t MODER;      /*!< GPIO port mode register */
    volatile uint32_t OTYPER;     /*!< GPIO port output type register */
    volatile uint32_t OSPEEDR;    /*!< GPIO port output speed register */
    volatile uint32_t PUPDR;      /*!< GPIO port pull-up/pull-down register */
    const volatile uint32_t IDR;  /*!< GPIO port input data register (read-only) */
    volatile uint32_t ODR;        /*!< GPIO port output data register */
    volatile uint32_t BSRR;       /*!< GPIO port bit set/reset register */
    volatile uint32_t LCKR;       /*!< GPIO port configuration lock register */
    volatile uint32_t AFRL;       /*!< GPIO alternate function low register */
    volatile uint32_t AFRH;       /*!< GPIO alternate function high register */
} GPIO_TypeDef;

#define GPIOA                     ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                     ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                     ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                     ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE                     ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF                     ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG                     ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH                     ((GPIO_TypeDef *) GPIOH_BASE)

/*******************************************************************************************
 * Timer Base Addresses (APB1 Timers)
 *******************************************************************************************/
#define TIM2_BASE                 (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE                 (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE                 (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE                 (APB1PERIPH_BASE + 0x0C00UL)

/* TODO: Define TIMx register structure and instances here */

#endif /* STM32F446RE_REGISTERS_H_ */

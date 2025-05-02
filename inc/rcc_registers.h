/*******************************************************************************************
 * @file    rcc_registers.h
 * @author  ka5j
 * @brief   STM32F446RE RCC Device Memory-Mapped Register Definitions (Bare Metal)
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Only memory-mapped register definitions for RCC modules.
 *          This file assumes a 32-bit embedded platform and no CMSIS dependency.
 *******************************************************************************************/

#ifndef RCC_REGISTERS_H_
#define RCC_REGISTERS_H_
  
#include <stdint.h>
#include "stm32f446re_addresses.h"

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

#endif
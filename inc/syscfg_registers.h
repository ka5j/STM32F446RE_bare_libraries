/*******************************************************************************************
 * @file    syscfg_registers.h
 * @author  ka5j
 * @brief   STM32F446RE SYSCFG Register Definitions (Bare Metal)
 * @version 1.0
 * @date    2025-05-06
 *
 * @note    This file defines memory-mapped register access for the SYSCFG peripheral.
 *          Used for external interrupt line mapping and system configuration options.
 *******************************************************************************************/

#ifndef SYSCFG_REGISTERS_H_
#define SYSCFG_REGISTERS_H_

#include <stdint.h>
#include "stm32f446re_addresses.h" // Must define APB2PERIPH_BASE

/*******************************************************************************************
 * SYSCFG Base Address
 * Located on the APB2 peripheral bus
 *******************************************************************************************/
#define SYSCFG_BASE (APB2PERIPH_BASE + 0x3800UL)

/*******************************************************************************************
 * SYSCFG Register Structure Definition
 * Reference Manual: Section 9.4
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t MEMRMP;  /*!< Memory Remap Register              (offset 0x00) */
    volatile uint32_t PMC;     /*!< Peripheral Mode Configuration      (offset 0x04) */
    volatile uint32_t EXTICR1; /*!< External Interrupt Config Reg 1    (offset 0x08) */
    volatile uint32_t EXTICR2; /*!< External Interrupt Config Reg 2    (offset 0x0C) */
    volatile uint32_t EXTICR3; /*!< External Interrupt Config Reg 3    (offset 0x10) */
    volatile uint32_t EXTICR4; /*!< External Interrupt Config Reg 4    (offset 0x14) */
    volatile uint32_t CMPCR;   /*!< Compensation Cell Control Register (offset 0x20) */
    volatile uint32_t CFGR;    /*!< Configuration Register              (offset 0x24) */
} SYSCFG_TypeDef;

/*******************************************************************************************
 * SYSCFG Peripheral Pointer
 *******************************************************************************************/
#define SYSCFG ((SYSCFG_TypeDef *)SYSCFG_BASE)

#endif /* SYSCFG_REGISTERS_H_ */

/*******************************************************************************************
 * @file    exti_registers.h
 * @author  ka5j
 * @brief   STM32F446RE EXTI (External Interrupt) Register Definitions (Bare Metal)
 * @version 1.0
 * @date    2025-05-06
 *
 * @note    This file defines memory-mapped register access for the EXTI peripheral.
 *          Assumes a 32-bit ARM Cortex-M4 STM32F446RE platform with no CMSIS dependency.
 *******************************************************************************************/

#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_

#include <stdint.h>
#include "stm32f446re_addresses.h" // Must define APB2PERIPH_BASE

/*******************************************************************************************
 * EXTI Base Address
 * Located on the APB2 peripheral bus
 *******************************************************************************************/
#define EXTI_BASE (APB2PERIPH_BASE + 0x3C00UL)

/*******************************************************************************************
 * EXTI Register Structure Definition
 * Maps to memory layout in STM32F446 Reference Manual (Section 12.3.1)
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t IMR;   /*!< Interrupt Mask Register        (offset 0x00) */
    volatile uint32_t EMR;   /*!< Event Mask Register            (offset 0x04) */
    volatile uint32_t RTSR;  /*!< Rising Trigger Selection Reg   (offset 0x08) */
    volatile uint32_t FTSR;  /*!< Falling Trigger Selection Reg  (offset 0x0C) */
    volatile uint32_t SWIER; /*!< Software Interrupt Event Reg   (offset 0x10) */
    volatile uint32_t PR;    /*!< Pending Register               (offset 0x14) */
} EXTI_TypeDef;

/*******************************************************************************************
 * EXTI Peripheral Pointer
 *******************************************************************************************/
#define EXTI ((EXTI_TypeDef *)EXTI_BASE)

#endif /* EXTI_REGISTERS_H_ */

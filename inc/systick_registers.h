/*******************************************************************************************
 * @file    systick_registers.h
 * @author  ka5j
 * @brief   STM32F446RE SysTick Device Memory-Mapped Register Definitions (Bare Metal)
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Only memory-mapped register definitions for SysTick modules.
 *          This file assumes a 32-bit embedded platform and no CMSIS dependency.
 *******************************************************************************************/

#ifndef SYSTICK_REGISTERS_H_
#define SYSTICK_REGISTERS_H_
   
#include <stdint.h>
#include "stm32f446re_addresses.h"

#define SYSTICK_BASE              (CORTEX_M4_PERIPH_BASE + 0xE010UL)

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

#endif
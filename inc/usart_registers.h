/*******************************************************************************************
 * @file    usart_registers.h
 * @author  ka5j
 * @brief   STM32F446RE USART Device Memory-Mapped Register Definitions (Bare Metal)
 * @version 1.0
 * @date    2025-05-14
 *
 * @note    Only memory-mapped register definitions for USART peripherals.
 *          This file assumes a 32-bit embedded platform and no CMSIS dependency.
 *******************************************************************************************/

#ifndef USART_REGISTERS_H_
#define USART_REGISTERS_H_

#include <stdint.h>
#include "stm32f446re_addresses.h"

/*******************************************************************************************
 * USART Base Addresses
 *******************************************************************************************/
#define USART1_BASE (APB2PERIPH_BASE + 0x1000UL)
#define USART2_BASE (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE (APB1PERIPH_BASE + 0x4800UL)
#define USART4_BASE (APB1PERIPH_BASE + 0x4C00UL)
#define USART5_BASE (APB1PERIPH_BASE + 0x5000UL)
#define USART6_BASE (APB2PERIPH_BASE + 0x1400UL)

/*******************************************************************************************
 * USART Register Definition
 *******************************************************************************************/
typedef struct
{
    volatile uint32_t SR;   /*!< Status register                          */
    volatile uint32_t DR;   /*!< Data register                            */
    volatile uint32_t BRR;  /*!< Baud rate register                       */
    volatile uint32_t CR1;  /*!< Control register 1                       */
    volatile uint32_t CR2;  /*!< Control register 2                       */
    volatile uint32_t CR3;  /*!< Control register 3                       */
    volatile uint32_t GTPR; /*!< Guard time and prescaler register        */
} USART_TypeDef;

/*******************************************************************************************
 * USART Peripheral Definitions
 *******************************************************************************************/
#define USART1 ((USART_TypeDef *)USART1_BASE)
#define USART2 ((USART_TypeDef *)USART2_BASE)
#define USART3 ((USART_TypeDef *)USART3_BASE)
#define USART4 ((USART_TypeDef *)USART4_BASE)
#define USART5 ((USART_TypeDef *)USART5_BASE)
#define USART6 ((USART_TypeDef *)USART6_BASE)

#endif /* USART_REGISTERS_H_ */

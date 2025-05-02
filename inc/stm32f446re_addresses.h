/*******************************************************************************************
 * @file    stm32f446re_addresses.h
 * @author  ka5j
 * @brief   STM32F446RE Device Memory-Mapped Addresses (Bare Metal)
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Only memory-mapped register addresses for core and peripheral modules.
 *          This file assumes a 32-bit embedded platform and no CMSIS dependency.
 *******************************************************************************************/

#ifndef STM32F446RE_ADDRESSES_H_
#define STM32F446RE_ADDRESSES_H_
 
#include <stdint.h>

 /*******************************************************************************************
 * Cortex-M4 Core Peripheral Base Addresses
 *******************************************************************************************/
#define CORTEX_M4_PERIPH_BASE     (0xE0000000UL)

 /*******************************************************************************************
 * Bus Peripheral Base Addresses
 *******************************************************************************************/
#define APB1PERIPH_BASE           (0x40000000UL)
#define APB2PERIPH_BASE           (0x40010000UL)
#define AHB1PERIPH_BASE           (0x40020000UL)
#define AHB2PERIPH_BASE           (0x50000000UL)
#define AHB3PERIPH_BASE           (0x60000000UL)

#endif /* STM32F446RE_REGISTERS_H_ */
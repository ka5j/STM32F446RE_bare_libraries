/*******************************************************************************************
 * @file    bare_usart.h
 * @author  ka5j
 * @brief   Bare-metal USART driver for STM32F446RE
 * @version 1.0
 * @date    2025-05-14
 *
 * @note    Provides high-level USART functionality without relying on STM32 HAL drivers.
 *          Includes basic TX/RX functions using memory-mapped registers.
 *******************************************************************************************/

#ifndef BARE_USART_H_
#define BARE_USART_H_

#include "stm32f446re_addresses.h" // Include low-level register definitions
#include "usart_registers.h"       // Include USART register map
#include "rcc_registers.h"         // Include RCC definitions for USART clock enable
#include <stdint.h>                // Include standard integer types

/*******************************************************************************************
 * API Function Prototypes
 *******************************************************************************************/

/**
 * @brief Initialize USART peripheral with default configuration (9600 8N1)
 *
 * This function enables USART2, configures baud rate, enables TX and RX,
 * and prepares the USART for basic serial communication.
 */
void bare_usart_init(void);

/**
 * @brief Send a single character over USART
 *
 * @param c Character to be transmitted
 */
void bare_usart_send_char(char c);

/**
 * @brief Send a null-terminated string over USART
 *
 * @param str Pointer to string to be transmitted
 */
void bare_usart_send_string(const char *str);

/**
 * @brief Read a single character from USART
 *
 * @return char Received character
 */
char bare_usart_read_char(void);

#endif /* BARE_USART_H_ */

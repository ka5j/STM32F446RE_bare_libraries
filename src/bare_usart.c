/*******************************************************************************************
 * @file    bare_usart.c
 * @author  ka5j
 * @brief   Bare-metal USART2 driver implementation for STM32F446RE
 * @version 1.0
 * @date    2025-05-14
 *
 * @note    Provides basic UART transmit and receive functionality using polling.
 *          Uses USART2 (PA2 TX / PA3 RX) at 115200 baud, 8N1. No interrupts used.
 *******************************************************************************************/

#include "bare_usart.h"
#include "stm32f446re_addresses.h"
#include "gpio_registers.h"
#include "bare_gpio.h"
#include "rcc_registers.h"
#include "usart_registers.h" // Must define USART2 base address and register map

/*******************************************************************************************
 *                                Configuration Constants
 *******************************************************************************************/
#define PCLK1_FREQ 16000000UL                                   /*!< APB1 peripheral clock frequency (Hz) */
#define USART_BAUD 115200UL                                     /*!< Desired USART baud rate */
#define USARTDIV ((PCLK1_FREQ + (USART_BAUD / 2)) / USART_BAUD) /*!< Rounded divisor */

/*******************************************************************************************
 *                               Public API Functions
 *******************************************************************************************/

/**
 * @brief  Initialize USART2 peripheral for 115200 baud, 8N1 configuration.
 *
 * @note   Uses GPIOA pins PA2 (TX) and PA3 (RX) in Alternate Function 7 (AF7).
 *         Configures TX, RX, and enables USART2 with polling-based I/O.
 */
void bare_usart_init(void)
{
    /* 1. Enable clocks for GPIOA and USART2 */
    bare_gpio_enable_clock(GPIOA);
    RCC->APB1ENR |= (1 << 17); // USART2 clock enable

    /* 2. Configure PA2 and PA3 to alternate function mode (AF7 = USART2) */
    bare_gpio_AF(GPIOA, 2);
    bare_gpio_AF(GPIOA, 3);

    GPIOA->AFRL &= ~(0xF << 8); // Clear AF bits for PA2
    GPIOA->AFRL |= (0x7 << 8);  // AF7 for PA2 (USART2_TX)

    GPIOA->AFRL &= ~(0xF << 12); // Clear AF bits for PA3
    GPIOA->AFRL |= (0x7 << 12);  // AF7 for PA3 (USART2_RX)

    /* 3. Disable USART before configuration */
    USART2->CR1 &= ~(1 << 13); // UE = 0

    /* 4. Set baud rate register (BRR) */
    USART2->BRR = USARTDIV;

    /* 5. Enable transmitter and receiver */
    USART2->CR1 |= (1 << 3); // TE = 1 (transmit enable)
    USART2->CR1 |= (1 << 2); // RE = 1 (receive enable)

    /* 6. Enable USART2 */
    USART2->CR1 |= (1 << 13); // UE = 1
}

/**
 * @brief  Send a single character over USART2.
 * @param  c: character to send
 */
void uart_send_char(char c)
{
    while (!(USART2->SR & (1 << 7)))
        ; // Wait for TXE (transmit buffer empty)
    USART2->DR = (uint8_t)c;
}

/**
 * @brief  Send a null-terminated string over USART2.
 * @param  str: pointer to null-terminated character array
 */
void uart_send_string(const char *str)
{
    while (*str)
    {
        uart_send_char(*str++);
    }
}

/**
 * @brief  Receive a single character via USART2.
 * @retval The received character
 */
char uart_read_char(void)
{
    while (!(USART2->SR & (1 << 5)))
        ; // Wait for RXNE (receive buffer not empty)
    return (char)(USART2->DR & 0xFF);
}

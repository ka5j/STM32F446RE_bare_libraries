/*******************************************************************************************
 * @file    bare_tim2_5.h
 * @author  ka5j
 * @brief   Bare-metal TIM2-TIM5 driver for STM32F446RE
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Provides high-level TIM2-TIM5 functionality without relying on STM32 HAL drivers.
 *******************************************************************************************/

#ifndef BARE_TIM2_5_H_
#define BARE_TIM2_5_H_
 
#include "stm32f446re_addresses.h"  // Include low-level register definitions
#include "tim2_5_registers.h"
#include "rcc_registers.h"
#include <stdint.h>            // Include standard integer types

/*******************************************************************************************
 * SysTick Configuration Constants
 *******************************************************************************************/
#define TIM2_5_1SEC_RELOAD_16MHZ 15999U  /*!< Prescaler value for 1s delay at 16 MHz */
#define TIM2_5_TIME 1000  /*!< Countdown value for 1s delay */

/*******************************************************************************************
 * GPIO Configuration Enumerations
 *******************************************************************************************/

/**
 * @brief GPIO Output Speeds
 */
typedef enum {
    TIM2_5_DISABLE     = 0x00U, /*!< Timer disabled */
    TIM2_5_ENABLE      = 0x01U /*!< Timer enabled */
} TIM2_5_CNTEN_t;

/**
 * @brief GPIO Output Speeds
 */
typedef enum {
    TIM2_5_INT_DISABLE     = 0x00U, /*!< Timer interrupt generation disabled */
    TIM2_5_INT_ENABLE      = 0x01U /*!< Timer interrupt generation enabled */
} TIM2_5_DIERINT_t;


/**
 * @brief GPIO Output Speeds
 */
typedef enum {
    TIM2_5_INT_CLEAR       = 0x00U, /*!< Timer interrupt flag clear */
    TIM2_5_INT_PENDING     = 0x01U /*!< Timer interrupt flag pending */
} TIM2_5_INTCLEAR_t;

/**
  * @brief SysTick Reload Value Definitions
  */
typedef enum {
    TIM2_5_PSC = TIM2_5_1SEC_RELOAD_16MHZ /*!< Reload value for 1-second delay */
} TIM2_5_PSC_t;

/**
  * @brief SysTick Reload Value Definitions
  */
 typedef enum {
    TIM2_5_ARR = TIM2_5_TIME /*!< Reload value for 1-second delay */
} TIM2_5_ARR_t;

/*******************************************************************************************
 * API Function Prototypes
 *******************************************************************************************/

/**
 * @brief Initialize a GPIO pin with specified configurations
 * 
 * @param GPIOx   Pointer to GPIO peripheral (e.g., GPIOA, GPIOB, etc.)
 * @param pin     GPIO pin number (0-15)
 * @param mode    Mode of the GPIO pin
 * @param otype   Output type configuration
 * @param speed   Output speed configuration
 * @param pull    Pull-up/Pull-down configuration
 */
void bare_tim2_5_start(TIM2_5_TypeDef *GPIOx);

/**
 * @brief Initialize a GPIO pin with specified configurations
 * 
 * @param GPIOx   Pointer to GPIO peripheral (e.g., GPIOA, GPIOB, etc.)
 * @param pin     GPIO pin number (0-15)
 * @param mode    Mode of the GPIO pin
 * @param otype   Output type configuration
 * @param speed   Output speed configuration
 * @param pull    Pull-up/Pull-down configuration
 */
void bare_tim2_5_set(TIM2_5_TypeDef *GPIOx);




#endif
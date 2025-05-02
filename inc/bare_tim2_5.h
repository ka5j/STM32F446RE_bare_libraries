/*******************************************************************************************
 * @file    bare_tim2_5.h
 * @author  ka5j
 * @brief   Bare-metal TIM2-TIM5 driver interface for STM32F446RE
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Provides high-level control over general-purpose timers TIM2–TIM5
 *          without relying on STM32 HAL drivers.
 *******************************************************************************************/

 #ifndef BARE_TIM2_5_H_
 #define BARE_TIM2_5_H_
 
 #include <stdint.h>                  // Standard integer types
 #include "stm32f446re_addresses.h"   // Peripheral base addresses
 #include "tim2_5_registers.h"        // Timer-specific register structures
 #include "rcc_registers.h"           // RCC peripheral definitions
 
 /*******************************************************************************************
  * Timer Configuration Constants
  *******************************************************************************************/
 
 // Prescaler value to get 1 kHz timer tick from 16 MHz clock
 #define TIM2_5_1KHZ_PRESCALER 15999U
 
 // Auto-reload value for 1-second cycle at 1 kHz tick rate
 #define TIM2_5_1SEC_ARR       1000U
 
 /*******************************************************************************************
  * Enumerations for Timer Control
  *******************************************************************************************/
/**
  * @brief Timer number
  */
 typedef enum {
    TIM_2  = 0x00U,  /*!< Timer disabled */
    TIM_3  = 0x01U,   /*!< Timer enabled */
    TIM_4  = 0x02U,   /*!< Timer enabled */
    TIM_5  = 0x03U   /*!< Timer enabled */
} TIM2_5_t;
 
 /**
  * @brief Timer enable/disable options
  */
 typedef enum {
     TIM2_5_DISABLE = 0x00U,  /*!< Timer disabled */
     TIM2_5_ENABLE  = 0x01U   /*!< Timer enabled */
 } TIM2_5_CNTEN_t;
 
 /**
  * @brief Timer interrupt enable/disable
  */
 typedef enum {
     TIM2_5_INT_DISABLE = 0x00U,  /*!< Interrupt disabled */
     TIM2_5_INT_ENABLE  = 0x01U   /*!< Interrupt enabled */
 } TIM2_5_DIERINT_t;
 
 /**
  * @brief Timer interrupt flag states
  */
 typedef enum {
     TIM2_5_INT_CLEAR   = 0x00U,  /*!< Interrupt flag clear */
     TIM2_5_INT_PENDING = 0x01U   /*!< Interrupt flag pending */
 } TIM2_5_INTCLEAR_t;
 
 /*******************************************************************************************
  * API Function Prototypes
  *******************************************************************************************/
 
 /**
  * @brief Start the specified TIM2–TIM5 timer
  * 
  * @param TIMx Pointer to timer peripheral (e.g., TIM2, TIM3, etc.)
  */
 void bare_tim2_5_start(TIM2_5_TypeDef *TIMx);
 
 /**
  * @brief Set or configure the specified TIM2–TIM5 timer (e.g., prescaler, ARR, PWM mode)
  * 
  * @param TIMx Pointer to timer peripheral (e.g., TIM2, TIM3, etc.)
  */
 void bare_tim2_5_set(TIM2_5_TypeDef *TIMx);
 
 /**
  * @brief Stop the specified TIM2–TIM5 timer
  * 
  * @param TIMx Pointer to timer peripheral (e.g., TIM2, TIM3, etc.)
  */
 void bare_tim2_5_stop(TIM2_5_TypeDef *TIMx);
 
 #endif // BARE_TIM2_5_H_
 
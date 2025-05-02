/*******************************************************************************************
 * @file    tim2_5__registers.h
 * @author  ka5j
 * @brief   STM32F446RE TIM2–TIM5 Device Memory-Mapped Register Definitions (Bare Metal)
 * @version 1.0
 * @date    2025-05-01
 *
 * @note    Defines TIM2 to TIM5 general-purpose timers.
 *          Assumes a 32-bit ARM Cortex-M4 system without CMSIS.
 *******************************************************************************************/

 #ifndef TIM2_5_REGISTERS_H_
 #define TIM2_5_REGISTERS_H_
 
 #include <stdint.h>
 #include "stm32f446re_addresses.h" 
 
 /*******************************************************************************************
  * TIM2–TIM5 Base Addresses (from RM0390 Reference Manual, Table 1)
  *******************************************************************************************/
 #define TIM2_BASE     (APB1PERIPH_BASE + 0x0000UL)
 #define TIM3_BASE     (APB1PERIPH_BASE + 0x0400UL)
 #define TIM4_BASE     (APB1PERIPH_BASE + 0x0800UL)
 #define TIM5_BASE     (APB1PERIPH_BASE + 0x0C00UL)
 
 /*******************************************************************************************
  * TIM Register Layout (Applies to TIM2–TIM5)
  *******************************************************************************************/
 typedef struct {
     volatile uint32_t CR1;     /*!< Control register 1 */
     volatile uint32_t CR2;     /*!< Control register 2 */
     volatile uint32_t SMCR;    /*!< Slave mode control register */
     volatile uint32_t DIER;    /*!< DMA/interrupt enable register */
     volatile uint32_t SR;      /*!< Status register */
     volatile uint32_t EGR;     /*!< Event generation register */
     volatile uint32_t CCMR1;   /*!< Capture/compare mode register 1 */
     volatile uint32_t CCMR2;   /*!< Capture/compare mode register 2 */
     volatile uint32_t CCER;    /*!< Capture/compare enable register */
     volatile uint32_t CNT;     /*!< Counter */
     volatile uint32_t PSC;     /*!< Prescaler */
     volatile uint32_t ARR;     /*!< Auto-reload register */
     volatile uint32_t RCR;     /*!< Repetition counter register */
     volatile uint32_t CCR1;    /*!< Capture/compare register 1 */
     volatile uint32_t CCR2;    /*!< Capture/compare register 2 */
     volatile uint32_t CCR3;    /*!< Capture/compare register 3 */
     volatile uint32_t CCR4;    /*!< Capture/compare register 4 */
     volatile uint32_t BDTR;    /*!< Break and dead-time register */
     volatile uint32_t DCR;     /*!< DMA control register */
     volatile uint32_t DMAR;    /*!< DMA address for full transfer */
 } TIM2_5_TypeDef;
 
 /*******************************************************************************************
  * TIM Peripheral Definitions
  *******************************************************************************************/
 #define TIM2    ((TIM2_5_TypeDef *) TIM2_BASE)
 #define TIM3    ((TIM2_5_TypeDef *) TIM3_BASE)
 #define TIM4    ((TIM2_5_TypeDef *) TIM4_BASE)
 #define TIM5    ((TIM2_5_TypeDef *) TIM5_BASE)
 
 #endif /* TIM_REGISTERS_H_ */
 
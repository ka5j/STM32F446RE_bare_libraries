/*******************************************************************************************
 * @file    bare_tim2_5.c
 * @author  ka5j
 * @brief   Bare-metal TIM2-TIM5 driver implementation for STM32F446RE
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Provides high-level TIM2-TIM5 functionality without HAL. 
 *******************************************************************************************/

 #include "stm32f446re_addresses.h"  // Include low-level register definitions
 #include "tim2_5_registers.h"
 #include "bare_tim2_5.h"
 #include "rcc_registers.h"
 #include "nvic_registers.h"

/*******************************************************************************************
 *                               Internal Helper Functions
 *******************************************************************************************/
/**
 * @brief  Enable RCC Clock for a given GPIO port
 * @param  GPIOx: pointer to GPIO peripheral base address
 * @retval None
 * 
 * @note   Must be called before accessing GPIO registers.
 */
static void bare_tim2_5_enable_clock(TIM2_5_TypeDef *TIMx){
    if(TIMx == TIM2){
        RCC->APB1ENR |= (1 << 0);
    }
    else if(TIMx == TIM3){
        RCC->APB1ENR |= (1 << 1);
    }
    else if(TIMx == TIM4){
        RCC->APB1ENR |= (1 << 2);
    }
    else if(TIMx == TIM5){
        RCC->APB1ENR |= (1 << 3);
    }

}

/**
 * @brief  Enable RCC Clock for a given GPIO port
 * @param  GPIOx: pointer to GPIO peripheral base address
 * @retval None
 * 
 * @note   Must be called before accessing GPIO registers.
 */
static void bare_tim2_5_disable_clock(TIM2_5_TypeDef *TIMx){
    if(TIMx == TIM2){
        RCC->APB1ENR &= ~(1 << 0);
    }
    else if(TIMx == TIM3){
        RCC->APB1ENR &= ~(1 << 1);
    }
    else if(TIMx == TIM4){
        RCC->APB1ENR &= ~(1 << 2);
    }
    else if(TIMx == TIM5){
        RCC->APB1ENR &= ~(1 << 3);
    }

}

/**
 * @brief  Enable RCC Clock for a given GPIO port
 * @param  GPIOx: pointer to GPIO peripheral base address
 * @retval None
 * 
 * @note   Must be called before accessing GPIO registers.
 */
static void bare_tim2_5_enable_interrupt(TIM2_5_TypeDef *TIMx){
    if(TIMx == TIM2){
        NVIC->ISER[0] |= (1 << 28);
    }
    else if(TIMx == TIM3){
        NVIC->ISER[0] |= (1 << 29);
    }
    else if(TIMx == TIM4){
        NVIC->ISER[0] |= (1 << 30);
    }
    else if(TIMx == TIM5){
        NVIC->ISER[1] |= (1 << (50 - 32));
    }

}

/**
 * @brief  Enable RCC Clock for a given GPIO port
 * @param  GPIOx: pointer to GPIO peripheral base address
 * @retval None
 * 
 * @note   Must be called before accessing GPIO registers.
 */
static void bare_tim2_5_disable_interrupt(TIM2_5_TypeDef *TIMx){
    if(TIMx == TIM2){
        NVIC->ISER[0] &= ~(1 << 28);
    }
    else if(TIMx == TIM3){
        NVIC->ISER[0] &= ~(1 << 29);
    }
    else if(TIMx == TIM4){
        NVIC->ISER[0] &= ~(1 << 30);
    }
    else if(TIMx == TIM5){
        NVIC->ISER[1] &= ~(1 << (50 - 32));
    }

}

/*******************************************************************************************
 *                               Public API Functions
 *******************************************************************************************/
/**
  * @brief Start the specified TIM2–TIM5 timer
  * 
  * @param TIMx Pointer to timer peripheral (e.g., TIM2, TIM3, etc.)
  */
 void bare_tim2_5_start(TIM2_5_TypeDef *TIMx){
    bare_tim2_5_enable_clock(TIMx);
    bare_tim2_5_enable_interrupt(TIMx);
    bare_tim2_5_set(TIMx);
    TIMx->DIER |= (1 << 0); // Enable update interrupt
	TIMx->CR1 |= (1 << 0); //Enable timer
 }

 /**
  * @brief Set or configure the specified TIM2–TIM5 timer (e.g., prescaler, ARR, PWM mode)
  * 
  * @param TIMx Pointer to timer peripheral (e.g., TIM2, TIM3, etc.)
  */
 void bare_tim2_5_set(TIM2_5_TypeDef *TIMx){
    TIMx->PSC = TIM2_5_1KHZ_PRESCALER;
    TIMx->ARR = TIM2_5_1SEC_ARR;
 }

 /**
  * @brief Stop the specified TIM2–TIM5 timer
  * 
  * @param TIMx Pointer to timer peripheral (e.g., TIM2, TIM3, etc.)
  */
 void bare_tim2_5_stop(TIM2_5_TypeDef *TIMx){
    TIMx->CR1 &= ~(1 << 0); //disable timer
    bare_tim2_5_disable_clock(TIMx);
    bare_tim2_5_disable_interrupt(TIMx);
 }
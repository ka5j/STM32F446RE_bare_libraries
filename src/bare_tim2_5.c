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
#ifndef DEVICE_REGISTERS_H_
#define DEVICE_REGISTERS_H_

#include <stdint.h>

//Base addresss for peripheral buses
#define APB1PERPH_BASE 0x40000000U
#define APB2PERPH_BASE 0x40010000U
#define AHB1PERPH_BASE 0x40020000U
#define AHB2PERPH_BASE 0x50000000U
#define AHB3PERPH_BASE 0x60000000U
#define M4PERPH_BASE   0xE0000000U

//SysTick base address
#define SYSTICK_BASE (M4PERPH_BASE + 0xE010U)

//NVIC base address
#define NVIC_BASE (M4PERPH_BASE + 0xE100U)

//RCC base address
#define RCC_BASE (AHB1PERPH_BASE + 0x3800U)

//EXTI Base address
#define EXTI_BASE (APB2PERPH_BASE + 0x3C00U)

//SYSCFG base address
#define SYSCFG_BASE (APB2PERPH_BASE + 0x3800U)

//GPIOx base addresses
#define GPIOA_BASE (AHB1PERPH_BASE + 0x0000U)
#define GPIOB_BASE (AHB1PERPH_BASE + 0x0400U)
#define GPIOC_BASE (AHB1PERPH_BASE + 0x0800U)
#define GPIOD_BASE (AHB1PERPH_BASE + 0x0C00U)
#define GPIOE_BASE (AHB1PERPH_BASE + 0x1000U)
#define GPIOF_BASE (AHB1PERPH_BASE + 0x1400U)
#define GPIOG_BASE (AHB1PERPH_BASE + 0x1800U)
#define GPIOH_BASE (AHB1PERPH_BASE + 0x1C00U)

//Timer base addresses
#define TIM2_BASE (APB1PERPH_BASE + 0x0000U)
#define TIM3_BASE (APB1PERPH_BASE + 0x0400U)
#define TIM4_BASE (APB1PERPH_BASE + 0x0800U)
#define TIM5_BASE (APB1PERPH_BASE + 0x0C00U)

typedef volatile struct{
    uint32_t MODER;    // GPIO Mode Register
    uint32_t OTYPER;   // GPIO Output Type Register
    uint32_t OSPEEDR;  // GPIO Output Speed Register
    uint32_t PUPDR;    // GPIO Pull-up/Pull-down Register
    uint32_t IDR;      // GPIO Input Data Register
    uint32_t ODR;      // GPIO Output Data Register
    uint32_t BSRR;     // GPIO Bit Set/Reset Register
    uint32_t LCKR;     // GPIO Lock Register
    uint32_t AFRL, AFRH;   // GPIO Alternate Function Registers
}GPIO_RegDef_t;


#endif /* BOARD_CONFIG_H_ */
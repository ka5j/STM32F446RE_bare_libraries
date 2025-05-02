/*******************************************************************************************
 * @file    bare_gpio.c
 * @author  ka5j
 * @brief   Bare-metal GPIO driver implementation for STM32F446RE
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    Provides high-level GPIO functionality without HAL. 
 *          Users can initialize, write, read, and toggle GPIO pins.
 *******************************************************************************************/

 #include "stm32f446re_addresses.h"  // Include low-level register definitions
 #include "gpio_registers.h"
 #include "bare_gpio.h"
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
static void bare_gpio_enable_clock(GPIO_TypeDef *GPIOx)
{
    if (GPIOx == GPIOA) {
        RCC->AHB1ENR |= (1 << 0);
    } else if (GPIOx == GPIOB) {
        RCC->AHB1ENR |= (1 << 1);
    } else if (GPIOx == GPIOC) {
        RCC->AHB1ENR |= (1 << 2);
    } else if (GPIOx == GPIOD) {
        RCC->AHB1ENR |= (1 << 3);
    } else if (GPIOx == GPIOE) {
        RCC->AHB1ENR |= (1 << 4);
    } else if (GPIOx == GPIOF) {
        RCC->AHB1ENR |= (1 << 5);
    } else if (GPIOx == GPIOG) {
        RCC->AHB1ENR |= (1 << 6);
    } else if (GPIOx == GPIOH) {
        RCC->AHB1ENR |= (1 << 7);
    }
}

/*******************************************************************************************
 *                               Public API Functions
 *******************************************************************************************/

/**
 * @brief  Initialize a GPIO pin
 * @param  GPIOx: pointer to GPIO peripheral base address
 * @param  pin: GPIO pin number (0-15)
 * @param  mode: GPIO mode (input, output, alternate, analog)
 * @param  otype: Output type (push-pull, open-drain)
 * @param  speed: Output speed (low, medium, fast, high)
 * @param  pull: Pull-up/pull-down configuration
 * @retval None
 */
void bare_gpio_init(GPIO_TypeDef *GPIOx, GPIO_Pins_t pin, GPIO_Mode_t mode,
                    GPIO_OType_t otype, GPIO_Speed_t speed, GPIO_Pull_t pull)
{
    /* Enable the clock for GPIO port */
    bare_gpio_enable_clock(GPIOx);

    /* 1. Configure GPIO mode */
    GPIOx->MODER &= ~(0x3U << (pin * 2)); // Clear existing mode
    GPIOx->MODER |= ((mode & 0x03U) << (pin * 2)); // Set new mode

    /* 2. Configure output type */
    GPIOx->OTYPER &= ~(0x1U << pin); // Clear
    GPIOx->OTYPER |= ((otype & 0x1U) << pin); // Set

    /* 3. Configure output speed */
    GPIOx->OSPEEDR &= ~(0x3U << (pin * 2)); // Clear
    GPIOx->OSPEEDR |= ((speed & 0x03U) << (pin * 2)); // Set

    /* 4. Configure pull-up/pull-down resistors */
    GPIOx->PUPDR &= ~(0x3U << (pin * 2)); // Clear
    GPIOx->PUPDR |= ((pull & 0x03U) << (pin * 2)); // Set
}

/**
 * @brief  Write to a GPIO pin (set high or low)
 * @param  GPIOx: pointer to GPIO peripheral base address
 * @param  pin: GPIO pin number (0-15)
 * @param  state: GPIO_PIN_HIGH or GPIO_PIN_LOW
 * @retval None
 */
void bare_gpio_write(GPIO_TypeDef *GPIOx, GPIO_Pins_t pin, GPIO_PinState_t state)
{
    if (state == GPIO_PIN_SET) {
        GPIOx->BSRR = (1U << pin); // Set bit (high)
    } else {
        GPIOx->BSRR = (1U << (pin + 16)); // Reset bit (low)
    }
}

/**
 * @brief  Read the input state of a GPIO pin
 * @param  GPIOx: pointer to GPIO peripheral base address
 * @param  pin: GPIO pin number (0-15)
 * @retval Pin state (0 or 1)
 */
GPIO_PinState_t bare_gpio_read(GPIO_TypeDef *GPIOx, GPIO_Pins_t pin)
{
    return (GPIO_PinState_t)((GPIOx->IDR >> pin) & 0x01);
}

/**
 * @brief  Toggle the output state of a GPIO pin
 * @param  GPIOx: pointer to GPIO peripheral base address
 * @param  pin: GPIO pin number (0-15)
 * @retval None
 */
void bare_gpio_toggle(GPIO_TypeDef *GPIOx, GPIO_Pins_t pin)
{
    GPIOx->ODR ^= (1U << pin);
}
#include "bare_gpio.h"

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

void bare_gpio_init(GPIO_TypeDef *GPIOx, uint8_t pin, GPIO_Mode_t mode,
    GPIO_OType_t otype, GPIO_Speed_t speed, GPIO_Pull_t pull)
    {
        bare_gpio_enable_clock(GPIOx);

        // Configure Mode
        GPIOx->MODER &= ~(0x3U << (pin * 2));    // Clear existing mode bits
        GPIOx->MODER |= ((mode & 0x3U) << (pin * 2)); // Set new mode

        // Configure Output Type
        GPIOx->OTYPER &= ~(0x1U << pin);          // Clear existing output type
        GPIOx->OTYPER |= ((otype & 0x1U) << pin); // Set output type

        // Configure Output Speed
        GPIOx->OSPEEDR &= ~(0x3U << (pin * 2));   // Clear speed bits
        GPIOx->OSPEEDR |= ((speed & 0x3U) << (pin * 2)); // Set speed

        // Configure Pull-up/Pull-down
        GPIOx->PUPDR &= ~(0x3U << (pin * 2));     // Clear pull-up/pull-down bits
        GPIOx->PUPDR |= ((pull & 0x3U) << (pin * 2)); // Set pull config
    }

void bare_gpio_write(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t state)
{
    if (state == GPIO_PIN_HIGH) {
        GPIOx->BSRR = (1U << pin); // Set bit (high)
    } else {
        GPIOx->BSRR = (1U << (pin + 16)); // Reset bit (low)
    }
}

uint8_t bare_gpio_read(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    return (uint8_t)((GPIOx->IDR >> pin) & 0x01);
}

void bare_gpio_toggle(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    GPIOx->ODR ^= (1U << pin);
}
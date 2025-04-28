#include "bare_gpio.h"

void bare_gpio_init(GPIO_TypeDef *GPIOx, uint8_t pin, GPIO_Mode_t mode,
    GPIO_OType_t otype, GPIO_Speed_t speed, GPIO_Pull_t pull){
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
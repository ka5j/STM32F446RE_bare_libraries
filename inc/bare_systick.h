#ifndef BARE_SYSTICK_H_
#define BARE_SYSTICK_H_

#include "device_registers.h"
#include <stdint.h>

#define SYSTICK_TICKS 16000000 // 1 second timer

typedef enum{
    SYSTICK_EXTERNAL_CLK = 0x00U,
    SYSTICK_PROCESSOR_CLK = 0x01U
}SysTick_Clk_t;

typedef enum{
    SYSTICK_DISABLE_INTERRUPT = 0x00U,
    SYSTICK_ENABLE_INTERRUPT = 0x01U
}SysTick_Interrupt_t;

typedef enum{
    SYSTICK_DISABLE = 0x00U,
    SYSTICK_ENABLE = 0x01U
}SysTick_Start_t;

#endif /* BARE_SYSTICK_H_ */
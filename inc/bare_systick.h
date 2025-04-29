#ifndef BARE_SYSTICK_H_
#define BARE_SYSTICK_H_

#include "device_registers.h"
#include <stdint.h>

#define SYSTICK_TICKS 16000000 // 1 second timer

typedef enum{
    EXTERNAL_CLK = 0x00U,
    PROCESSOR_CLK = 0x01U
}SysTick_Clk_t;

#endif /* BARE_SYSTICK_H_ */
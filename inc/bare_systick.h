#ifndef BARE_SYSTICK_H_
#define BARE_SYSTICK_H_

#include "device_registers.h"
#include <stdint.h>

#define SYSTICK_TICKS 16000000 // 1 second timer

typedef enum{
    SYSTICK_EXTERNAL_CLK = 0x00U,
    SYSTICK_PROCESSOR_CLK = 0x01U
}SysTick_CSRClk_t;

typedef enum{
    SYSTICK_DISABLE_INTERRUPT = 0x00U,
    SYSTICK_ENABLE_INTERRUPT = 0x01U
}SysTick_CSRInterrupt_t;

typedef enum{
    SYSTICK_DISABLE = 0x00U,
    SYSTICK_ENABLE = 0x01U
}SysTick_CSRStart_t;

typedef enum{
    SYSTICK_RELOAD = SYSTICK_TICKS
}SysTick_RVR_t;

typedef enum{
    SYSTICK_CLK_nIMPL = 0x00U,
    SYSTICK_CLK_IMPL = 0x01U

}SysTick_CALIBCLK_t;

typedef enum{
    SYSTICK_CALIB = 0x00U,
    SYSTICK_nCALIB = 0x01U
}SysTick_CALIBFREQ_t;

void SysTick_Init(SysTick_TypeDef *SysTick, SysTick_RVR_t reload, SysTick_CSRClk_t clk,
                    SysTick_CSRInterrupt_t interrupt, SysTick_CALIBCLK_t impl, SysTick_CALIBFREQ_t calib);

void SysTick_Set_TIMER(SysTick_TypeDef *SysTick, SysTick_RVR_t reload);
#endif /* BARE_SYSTICK_H_ */
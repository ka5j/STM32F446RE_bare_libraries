#include "bare_systick.h"      
#include "device_registers.h"

void SysTick_Init(SysTick_RVR_t reload, SysTick_CSRClk_t clk,
    SysTick_CSRInterrupt_t interrupt, SysTick_CALIBCLK_t impl, SysTick_CALIBFREQ_t calib){
        SysTick_Set_TIMER(reload);
        SYSTICK->CSR |= (1 << 2);   // Use processor clock
        SYSTICK->CSR |= (1 << 1);   // Enable SysTick interrupt
        SYSTICK->CSR |= (1 << 0);   // Enable SysTick
    }

    void SysTick_Set_TIMER(SysTick_RVR_t reload){
        SYSTICK->RVR = reload;
        SYSTICK->CVR = 0;
    }

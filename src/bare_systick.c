/*******************************************************************************************
 * @file    bare_systick.c
 * @author  ka5j
 * @brief   SysTick timer driver implementation for STM32F446RE (bare-metal)
 * @version 1.1
 * @date    2025-05-01
 *
 * @note    This file provides the implementation for basic SysTick timer configuration
 *          without using STM32 HAL. It enables timing-based functionality using the
 *          Cortex-M system timer.
 *******************************************************************************************/

 #include "stm32f446re_addresses.h"  // Low-level register definitions
 #include "systick_registers.h"
 #include "bare_systick.h"
 
 /*******************************************************************************************
  * @brief  Initialize the SysTick timer
  *
  * This function configures the SysTick timer with the given reload value and control
  * settings (clock source, interrupt enable, and calibration status). It is typically used
  * to set up time delays or periodic interrupts in a bare-metal embedded system.
  *
  * @param reload     Reload value for the timer (e.g., 16000000 for 1 second delay)
  * @param clk        Clock source selection (external or processor clock)
  * @param interrupt  Enable or disable SysTick interrupt
  * @param impl       Indicates if reference clock is implemented
  * @param calib      Indicates if calibration value is accurate (10ms or not)
  *******************************************************************************************/
 void SysTick_Init(SysTick_RVR_t reload, 
                   SysTick_CSRClk_t clk,
                   SysTick_CSRInterrupt_t interrupt, 
                   SysTick_CALIBCLK_t impl, 
                   SysTick_CALIBFREQ_t calib)
 {
     // Set the reload value and reset current value
     SysTick_Set_TIMER(reload);
 
     // Configure SysTick Control and Status Register (CSR)
     SYSTICK->CSR |= (clk << 2);  // Set CLKSOURCE bit to use processor clock
     SYSTICK->CSR |= (interrupt << 1);  // Enable SysTick interrupt
     SYSTICK->CSR |= (SYSTICK_ENABLE << 0);      // Enable SysTick timer
 }
 
 /*******************************************************************************************
  * @brief  Set SysTick reload value and reset current value
  *
  * This function loads a new reload value into the SysTick Reload Value Register (RVR)
  * and clears the current value register (CVR) to start counting from the top.
  *
  * @param reload     New reload value for the timer
  *******************************************************************************************/
 void SysTick_Set_TIMER(SysTick_RVR_t reload)
 {
     SYSTICK->RVR = reload;  // Set reload value
     SYSTICK->CVR = 0;       // Reset current value
 }
 
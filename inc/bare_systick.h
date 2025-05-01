/*******************************************************************************************
 * @file    bare_systick.h
 * @author  ka5j
 * @brief   Bare-metal SysTick timer driver for STM32F446RE
 * @version 1.0
 * @date    2025-05-01
 *
 * @note    Provides basic SysTick configuration and control without relying on STM32 HAL.
 *******************************************************************************************/

 #ifndef BARE_SYSTICK_H_
 #define BARE_SYSTICK_H_
 
 #include "device_registers.h"  // Low-level register definitions
 #include <stdint.h>            // Standard integer types
 
 /*******************************************************************************************
  * SysTick Configuration Macros
  *******************************************************************************************/
 #define SYSTICK_TICKS 16000000U  /*!< Number of ticks for 1-second delay at 16 MHz */
 
 /*******************************************************************************************
  * SysTick Control Enumerations
  *******************************************************************************************/
 
 /**
  * @brief SysTick Clock Source Selection
  */
 typedef enum {
     SYSTICK_EXTERNAL_CLK  = 0x00U, /*!< Use external reference clock */
     SYSTICK_PROCESSOR_CLK = 0x01U  /*!< Use processor (AHB) clock */
 } SysTick_CSRClk_t;
 
 /**
  * @brief SysTick Interrupt Enable/Disable
  */
 typedef enum {
     SYSTICK_DISABLE_INTERRUPT = 0x00U, /*!< Disable SysTick interrupt */
     SYSTICK_ENABLE_INTERRUPT  = 0x01U  /*!< Enable SysTick interrupt */
 } SysTick_CSRInterrupt_t;
 
 /**
  * @brief SysTick Counter Enable/Disable
  */
 typedef enum {
     SYSTICK_DISABLE = 0x00U, /*!< Stop SysTick timer */
     SYSTICK_ENABLE  = 0x01U  /*!< Start SysTick timer */
 } SysTick_CSRStart_t;
 
 /**
  * @brief SysTick Reload Value Definitions
  */
 typedef enum {
     SYSTICK_RELOAD = SYSTICK_TICKS /*!< Reload value for 1-second delay */
 } SysTick_RVR_t;
 
 /**
  * @brief SysTick Calibration Clock Source Availability
  */
 typedef enum {
     SYSTICK_CLK_nIMPL = 0x00U, /*!< Reference clock not implemented */
     SYSTICK_CLK_IMPL  = 0x01U  /*!< Reference clock implemented */
 } SysTick_CALIBCLK_t;
 
 /**
  * @brief SysTick Calibration Value Accuracy
  */
 typedef enum {
     SYSTICK_CALIB   = 0x00U, /*!< Calibration value equals 10 ms */
     SYSTICK_nCALIB  = 0x01U  /*!< Calibration value not equal to 10 ms */
 } SysTick_CALIBFREQ_t;
 
 /*******************************************************************************************
  * API Function Prototypes
  *******************************************************************************************/
 
 /**
  * @brief Initialize the SysTick timer with configuration options.
  *
  * @param reload     Reload value for timer (e.g., SYSTICK_RELOAD)
  * @param clk        Clock source selection
  * @param interrupt  Enable or disable SysTick interrupt
  * @param impl       Clock implementation flag (from calibration register)
  * @param calib      Calibration accuracy flag
  */
 void SysTick_Init(SysTick_RVR_t reload, 
                   SysTick_CSRClk_t clk,
                   SysTick_CSRInterrupt_t interrupt,
                   SysTick_CALIBCLK_t impl,
                   SysTick_CALIBFREQ_t calib);
 
 /**
  * @brief Update the SysTick reload value during runtime.
  *
  * @param reload     Reload value for timer (e.g., SYSTICK_RELOAD)
  */
 void SysTick_Set_TIMER(SysTick_RVR_t reload);
 
 #endif /* BARE_SYSTICK_H_ */
 
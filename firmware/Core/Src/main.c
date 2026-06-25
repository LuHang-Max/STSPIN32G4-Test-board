/**
 * @file    main.c
 * @brief   STSPIN32G4 BLDC Motor Control - Firmware Entry
 * @author  LuHang
 * @date    2026-06-25
 *
 * Target:  STSPIN32G4 (Cortex-M4 @ 170 MHz)
 * HAL:     STM32 HAL Library
 * RTOS:    RT-Thread (RTT)
 * Debug:   SEGGER RTT
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"
#include "SEGGER_RTT.h"

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  System Clock Configuration
 *         Configures HSE/PLL for 170 MHz system clock
 */
void SystemClock_Config(void)
{
    // TODO: Configured by STM32CubeMX
    // - HSE: external crystal (if used)
    // - PLL: 170 MHz system clock
    // - APB1/APB2: appropriate prescalers
}

/**
 * @brief  GPIO Initialization
 */
void GPIO_Init(void)
{
    // TODO: Configured by STM32CubeMX
    // - LED pins
    // - Debug SWD pins
    // - Motor control IOs
}

/**
 * @brief  Main entry point
 */
int main(void)
{
    /* MCU Configuration */
    HAL_Init();
    SystemClock_Config();
    GPIO_Init();

    /* Initialize SEGGER RTT */
    SEGGER_RTT_Init();
    SEGGER_RTT_printf(0, "========================================\n");
    SEGGER_RTT_printf(0, "  STSPIN32G4 BLDC Motor Control Board\n");
    SEGGER_RTT_printf(0, "  System Clock: 170 MHz\n");
    SEGGER_RTT_printf(0, "  RT-Thread Initializing...\n");
    SEGGER_RTT_printf(0, "========================================\n\n");

    /* TODO: RT-Thread Scheduler Start */
    // rt_system_scheduler_start();

    /* Super Loop (if not using RTOS) */
    while (1)
    {
        // Toggle LED or other heartbeat
        HAL_Delay(500);
        SEGGER_RTT_printf(0, "[INFO] Heartbeat - System Running\n");
    }
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    SEGGER_RTT_printf(0, "[ASSERT] Wrong parameters value: file %s on line %d\r\n", file, line);
    while (1)
    {
    }
}
#endif /* USE_FULL_ASSERT */

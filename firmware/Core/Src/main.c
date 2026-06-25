/**
 * @file    main.c
 * @brief   STSPIN32G4 BLDC Motor Control - Firmware Entry
 * @author  LuHang
 * @date    2026-06-25
 *
 * Target:  STSPIN32G4 (Cortex-M4 @ 170 MHz)
 * HAL:     STM32 HAL Library
 * RTOS:    FreeRTOS
 * Debug:   DAP-Link (SWD + Serial)
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

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
    // - Debug SWD pins (SWCLK/SWDIO for DAP-Link)
    // - Motor control IOs
}

/**
 * @brief  UART Initialization (for DAP-Link serial printf)
 */
void UART_Init(void)
{
    // TODO: Configure UART for DAP-Link debug output
    // DAP-Link provides a virtual COM port over SWD
}

/**
 * @brief  Redirect printf to UART (for DAP-Link virtual COM)
 */
#ifdef __GNUC__
int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;
}
#endif

/**
 * @brief  Motor Control Task
 */
void MotorCtrl_Task(void *pvParameters)
{
    printf("[INFO] Motor Control Task started\n");
    while (1)
    {
        // TODO: Motor control loop (FOC / 6-step commutation)
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

/**
 * @brief  Heartbeat Task
 */
void Heartbeat_Task(void *pvParameters)
{
    printf("[INFO] Heartbeat Task started\n");
    while (1)
    {
        HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
        printf("[INFO] Heartbeat - System Running\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
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
    UART_Init();

    printf("========================================\r\n");
    printf("  STSPIN32G4 BLDC Motor Control Board\r\n");
    printf("  System Clock: 170 MHz\r\n");
    printf("  RTOS: FreeRTOS\r\n");
    printf("  Debug: DAP-Link\r\n");
    printf("========================================\r\n\r\n");

    /* Create FreeRTOS Tasks */
    xTaskCreate(Heartbeat_Task, "Heartbeat", 128, NULL, 1, NULL);
    xTaskCreate(MotorCtrl_Task, "MotorCtrl", 512, NULL, 3, NULL);

    /* Start FreeRTOS Scheduler */
    printf("[INFO] Starting FreeRTOS Scheduler...\r\n");
    vTaskStartScheduler();

    /* Should never reach here */
    while (1)
    {
    }
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    printf("[ASSERT] Wrong parameters value: file %s on line %d\r\n", file, line);
    while (1)
    {
    }
}
#endif /* USE_FULL_ASSERT */

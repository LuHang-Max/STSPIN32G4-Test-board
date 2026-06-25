# FreeRTOS

本项目使用 **FreeRTOS** 作为实时操作系统。

## 获取 FreeRTOS 源码

FreeRTOS 可通过以下方式获取：

| 方式 | 说明 |
|---|---|
| [FreeRTOS 官网](https://www.freertos.org/) | 下载最新稳定版 |
| [GitHub](https://github.com/FreeRTOS/FreeRTOS-Kernel) | 仅内核源码 |
| STM32CubeMX | 生成代码时勾选 FreeRTOS，自动包含 |

**需要包含的文件 (最小内核)：**
```
FreeRTOS/
├── Source/
│   ├── croutine.c
│   ├── event_groups.c
│   ├── list.c
│   ├── queue.c
│   ├── stream_buffer.c
│   ├── tasks.c
│   ├── timers.c
│   ├── include/          # 头文件
│   └── portable/         # 移植层 (ARM Cortex-M4)
├── FreeRTOSConfig.h      # 用户配置文件
└── README.md
```

## 集成方式

### 方式一：CubeMX 自动生成

1. 打开 STM32CubeMX → Middleware → **FREERTOS** → Enabled
2. 配置任务、队列、信号量
3. 生成代码后，FreeRTOS 源码会自动放入 `firmware/Middleware/FreeRTOS/`

### 方式二：手动集成

1. 下载 [FreeRTOS-Kernel](https://github.com/FreeRTOS/FreeRTOS-Kernel)
2. 将源码放入 `firmware/FreeRTOS/`
3. 创建 `FreeRTOSConfig.h` 配置文件

## 基本配置示例 (FreeRTOSConfig.h)

```c
#define configUSE_PREEMPTION                    1
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCPU_CLOCK_HZ                      ( SystemCoreClock )
#define configTICK_RATE_HZ                      ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES                    8
#define configMINIMAL_STACK_SIZE                ( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) ( 15 * 1024 ) )
#define configMAX_TASK_NAME_LEN                 16
#define configUSE_MUTEXES                       1
#define configUSE_COUNTING_SEMAPHORES           1
```

## 创建任务示例

```c
#include "FreeRTOS.h"
#include "task.h"

void MotorCtrl_Task(void *pvParameters)
{
    while (1)
    {
        // 电机控制逻辑
        vTaskDelay(pdMS_TO_TICKS(1));  // 1ms 周期
    }
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    xTaskCreate(MotorCtrl_Task, "Motor", 512, NULL, 3, NULL);
    vTaskStartScheduler();

    while (1) {}
}
```

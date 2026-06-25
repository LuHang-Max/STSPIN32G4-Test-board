# Firmware

STSPIN32G4 固件开发，基于 **STM32 HAL + FreeRTOS**。

## 开发环境搭建

### 1. 安装工具链

| 工具 | 下载地址 |
|---|---|
| STM32CubeIDE | https://www.st.com/stm32cubeide |
| Keil MDK | https://www.keil.com/download/product/ |
| STM32CubeMX | https://www.st.com/stm32cubemx |
| FreeRTOS | https://www.freertos.org/ |
| DAP-Link | 板载调试器或独立 DAP-Link |

### 2. 生成初始化代码

1. 打开 STM32CubeMX，新建工程，选择 **STSPIN32G4**
2. 配置时钟、外设、引脚（参考 `docs/pin-mapping.md`）
3. Middleware → FREERTOS → Enabled，配置任务
4. 生成代码，选择 **STM32CubeIDE** 或 **Keil MDK** 作为目标 IDE
5. 将生成的代码合并到 `firmware/` 对应目录

### 3. 集成 FreeRTOS

1. 通过 STM32CubeMX 勾选 FreeRTOS，自动生成到 `firmware/Middleware/FreeRTOS/`
2. 手动集成请参考 `firmware/FreeRTOS/README.md`

## 目录结构

```
firmware/
├── Core/
│   ├── Inc/          # 用户头文件（应用逻辑 .h）
│   └── Src/          # 用户源码（main.c 等）
├── Drivers/          # HAL 驱动库（CubeMX 生成）
├── Middleware/       # 中间件（FreeRTOS 等，CubeMX 自动生成）
├── FreeRTOS/         # FreeRTOS 源码（手动集成时使用，含 FreeRTOSConfig.h）
├── STM32CubeIDE/     # STM32CubeIDE 工程文件
├── Keil/             # Keil MDK 工程文件
└── tests/            # 单元测试
```

## 编译 & 烧录

### STM32CubeIDE
```bash
# 导入工程 → Project → Build All → Run → Debug
```

### Keil MDK
```bash
# 打开 .uvprojx → Build (F7) → Download (F8)
# DAP-Link 选 CMSIS-DAP Debugger
```

## DAP-Link 调试

使用 DAP-Link 进行 SWD 调试和串口输出：
1. 连接 DAP-Link 到板子 SWD 接口 (SWCLK/SWDIO/GND/VCC)
2. DAP-Link 虚拟串口连接到 MCU 的 UART TX/RX
3. 打开串口助手 (115200 波特率) 查看 printf 输出
4. IDE 中 Debug 配置选择 **CMSIS-DAP** 调试器

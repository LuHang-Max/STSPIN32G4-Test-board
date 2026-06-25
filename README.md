# STSPIN32G4 Test Board

基于 **STSPIN32G4** 的无刷直流电机 (BLDC) 控制板，用于学习和开发电机控制应用。

STSPIN32G4 是 STMicroelectronics 的一款集成度很高的系统级封装 (SiP)，内部集成了：
- **Cortex-M4** MCU (170 MHz, FPU, DSP)
- **三相栅极驱动器** (600 mA sink/source)
- **3.3V DC-DC 降压转换器**
- **12V LDO 线性稳压器**
- 多路运放、比较器、ADC

## 开发环境

| 工具 | 版本 / 说明 |
|---|---|
| **硬件设计** | Altium Designer v23.3.1 |
| **固件 IDE** | STM32CubeIDE + Keil MDK |
| **HAL 库** | STM32 HAL Library (通过 STM32CubeMX 生成) |
| **RTOS** | RT-Thread (RTT) |
| **调试工具** | SEGGER J-Link + RTT Viewer |
| **3D 模型** | 机械结构 / 外壳设计 |

## 项目结构

```
STSPIN32G4-Test-board/
├── Hardware/                     # Altium Designer 硬件工程
│   └── MotoCtrl_Rev_1.0.0/       # PCB 版本 Rev 1.0.0
│       ├── MotoCtrl_Rev_1.0.0.PrjPcb   # 项目文件
│       ├── TopLevel.SchDoc             # 顶层原理图
│       ├── MCU.SchDoc                  # MCU 主控原理图
│       ├── DRV.SchDoc                  # 电机驱动原理图
│       ├── POW.SchDoc                  # 电源原理图
│       ├── COMM.SchDoc                 # 通信接口原理图
│       ├── HMI_SENSOR.SchDoc           # 人机交互 & 传感器
│       ├── MotoCtrl_Rev_1.0.0.PcbDoc   # PCB 布局
│       ├── STSPIN32G4-Test-board.SchLib # 原理图符号库
│       └── STSPIN32G4-Test-board.PcbLib # PCB 封装库
├── firmware/                     # STSPIN32G4 固件
│   ├── Core/Inc/                 # 用户头文件
│   ├── Core/Src/                 # 用户源码
│   ├── Drivers/                  # HAL 驱动（CubeMX 生成）
│   ├── Middleware/               # 中间件（FreeRTOS 等）
│   ├── RTT/                      # SEGGER RTT 源码
│   ├── STM32CubeIDE/             # CubeIDE 工程
│   └── Keil/                     # Keil MDK 工程
├── docs/                         # 硬件设计文档
│   ├── block-diagram.md          # 系统框图
│   └── pin-mapping.md            # 引脚分配表
├── datasheets/                   # 数据手册索引
├── mechanical/                   # 3D 模型 & 外壳设计
│   └── models/
├── .gitattributes                # Git 二进制文件配置
├── .gitignore                    # Git 忽略规则
├── LICENSE                       # MIT License
└── CLAUDE.md                     # AI 辅助开发指南
```

## 快速开始

### 硬件设计

用 Altium Designer v23.3.1 或更高版本打开 `Hardware/MotoCtrl_Rev_1.0.0/MotoCtrl_Rev_1.0.0.PrjPcb`。

### 固件开发

1. 安装 **STM32CubeIDE** 和 **Keil MDK**
2. 用 STM32CubeMX 生成初始化代码（配置 STSPIN32G4）
3. 将 HAL 驱动放入 `firmware/Drivers/`
4. 将 RT-Thread 源码放入 `firmware/RTT/`
5. 在 `firmware/Core/Src/main.c` 中编写应用逻辑

## 许可证

本项目采用 [MIT License](LICENSE)。

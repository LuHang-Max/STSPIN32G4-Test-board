# Firmware

STSPIN32G4 固件开发，基于 **STM32 HAL + RT-Thread**。

## 开发环境搭建

### 1. 安装工具链

| 工具 | 下载地址 |
|---|---|
| STM32CubeIDE | https://www.st.com/stm32cubeide |
| Keil MDK | https://www.keil.com/download/product/ |
| STM32CubeMX | https://www.st.com/stm32cubemx |
| SEGGER J-Link | https://www.segger.com/downloads/jlink/ |
| RT-Thread | https://github.com/RT-Thread/rt-thread |

### 2. 生成初始化代码

1. 打开 STM32CubeMX，新建工程，选择 **STSPIN32G4**
2. 配置时钟、外设、引脚（参考 `docs/pin-mapping.md`）
3. 生成代码，选择 **STM32CubeIDE** 或 **Keil MDK** 作为目标 IDE
4. 将生成的代码合并到 `firmware/` 对应目录

### 3. 集成 RT-Thread

1. 将 RT-Thread 源码放入 `firmware/RTT/`
2. 参考 `firmware/RTT/README.md` 中的移植说明

## 目录结构

```
firmware/
├── Core/
│   ├── Inc/          # 用户头文件（应用逻辑 .h）
│   └── Src/          # 用户源码（main.c 等）
├── Drivers/          # HAL 驱动库（CubeMX 生成）
├── Middleware/       # 中间件（FreeRTOS / 文件系统等）
├── RTT/              # SEGGER RTT 源码（从 J-Link 安装目录复制）
├── STM32CubeIDE/     # STM32CubeIDE 工程文件
└── Keil/             # Keil MDK 工程文件
```

## 编译 & 烧录

### STM32CubeIDE
```bash
# 导入工程 → Project → Build All → Run → Debug
```

### Keil MDK
```bash
# 打开 .uvprojx → Build (F7) → Download (F8)
```

## RTT 调试输出

使用 SEGGER RTT Viewer 查看日志输出：
1. 连接 J-Link 到 SWD 接口
2. 打开 J-Link RTT Viewer
3. 选择 STSPIN32G4 芯片，连接即可看到 RTT 打印

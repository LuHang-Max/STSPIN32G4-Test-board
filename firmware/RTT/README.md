# SEGGER RTT (Real-Time Transfer)

RTT 是 SEGGER 为 J-Link 调试器开发的高速 printf 调试输出方案，比串口更快，不占用 UART 外设。

## 获取 RTT 源码

RTT 源码位于 J-Link 安装目录中：

**Windows:**
```
C:\Program Files\SEGGER\JLink\Samples\RTT\
```

**需要复制的文件：**
```
SEGGER_RTT.c
SEGGER_RTT.h
SEGGER_RTT_Conf.h
SEGGER_RTT_printf.c
```

将以上文件复制到 `firmware/RTT/` 目录下。

## 使用说明

### 1. 在 main.c 中包含头文件

```c
#include "SEGGER_RTT.h"
```

### 2. 初始化并输出

```c
SEGGER_RTT_Init();
SEGGER_RTT_printf(0, "Hello STSPIN32G4!\n");
```

### 3. 使用 J-Link RTT Viewer 查看输出

1. 打开 **J-Link RTT Viewer**（开始菜单 → SEGGER → J-Link RTT Viewer）
2. Connection Settings:
   - **Target Device**: STSPIN32G4
   - **Target Interface**: SWD
   - **Speed**: 4000 kHz
3. 点击 OK 连接
4. 终端窗口将显示 RTT 输出

## 注意事项

- RTT 依赖 **J-Link SWD 连接**，确认硬件 SWD 接口 (SWCLK/SWDIO) 连接正确
- RTT 通道 0 默认用于终端输出
- 可在 `SEGGER_RTT_Conf.h` 中调整上行/下行缓冲区大小
- 编译时确保包含 RTT 源文件的路径

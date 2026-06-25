# STSPIN32G4 引脚分配表

> ⚠️ 此表为模板，请在 Altium 中完成原理图设计后更新。
> 参考原理图：`MCU.SchDoc`、`DRV.SchDoc`

## 电源引脚

| 引脚 | 功能 | 连接 | 备注 |
|---|---|---|---|
| VIN | 电源输入 | 12-48V 输入 | 宽电压输入 |
| VDD | 12V LDO 输出 | 栅极驱动供电 | 内部 LDO |
| VCC | 3.3V DC-DC 输出 | MCU 数字供电 | 内部 DC-DC |
| VREG | 内部稳压 | 外部电容 | 1.8V 内核 |
| GND | 地 | 系统地 | |

## SWD 调试接口

| 引脚 | 功能 | 连接器 |
|---|---|---|
| SWCLK | 时钟 | SWD 调试口 |
| SWDIO | 数据 | SWD 调试口 |
| NRST | 复位 | SWD 调试口 |
| GND | 地 | SWD 调试口 |

## 栅极驱动输出

| 引脚 | 功能 | 备注 |
|---|---|---|
| GH1 / GL1 | U 相上/下桥 | → U 相 MOSFET |
| GH2 / GL2 | V 相上/下桥 | → V 相 MOSFET |
| GH3 / GL3 | W 相上/下桥 | → W 相 MOSFET |

## 运放 / 比较器

| 引脚 | 功能 | 备注 |
|---|---|---|
| OPAMP1+ / OPAMP1- / OPAMP1 OUT | 运放 1 (U 相电流) | 电流采样 |
| OPAMP2+ / OPAMP2- / OPAMP2 OUT | 运放 2 (V 相电流) | 电流采样 |
| OPAMP3+ / OPAMP3- / OPAMP3 OUT | 运放 3 (W 相电流) | 电流采样 |
| CP1 / CP2 / CP3 / CP4 | 比较器 | 过流保护 / BEMF 检测 |

## 通信接口

| 外设 | 引脚 | 功能 | 连接器 |
|---|---|---|---|
| USART1 TX/RX | PA9/PA10 | 调试串口 | 排针 / USB-TTL |
| SPI1 SCK/MISO/MOSI | TBD | SPI 通信 | TBD |
| CAN TX/RX | TBD | CAN 总线 | TBD |
| USB DP/DM | TBD | USB 接口 | USB 连接器 |

## 传感器 / 控制 IO

| 引脚 | 功能 | 备注 |
|---|---|---|
| TBD | Hall A / B / C | 霍尔传感器输入 |
| TBD | Encoder A / B / Z | 编码器输入 |
| TBD | NTC | 温度检测 |
| TBD | VBUS ADC | 母线电压检测 |
| TBD | PWM / SPEED | 电位器调速输入 |
| TBD | LED1 / LED2 | 状态指示灯 |
| TBD | KEY1 / KEY2 | 用户按键 |

> **TBD** = 待原理图设计完成后确定

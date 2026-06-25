# Firmware Tests

STSPIN32G4 固件单元测试。

## 测试框架

推荐使用以下任一框架：

| 框架 | 特点 | 适用场景 |
|---|---|---|
| [CppUTest](https://cpputest.github.io/) | C/C++ 测试，轻量 | 嵌入式 C 代码单元测试 |
| [Unity](http://www.throwtheswitch.org/unity) | 纯 C，极轻量 | 裸机 / RTOS 项目 |
| [CMock](http://www.throwtheswitch.org/cmock) | Mock 框架 (配合 Unity) | HAL 层 Mock |
| [Ceedling](http://www.throwtheswitch.org/ceedling) | Unity + CMock 集成 | 一键测试 |

## 目录结构

```
tests/
├── README.md           # 本文件
├── unity/              # Unity 测试框架 (git submodule 或直接引入)
├── mocks/              # Mock 文件 (模拟 HAL 接口)
├── test_motor/         # 电机控制逻辑测试
├── test_comm/          # 通信协议测试
└── test_utils/         # 工具函数测试
```

## 快速开始

### 安装 Ceedling (推荐)

```bash
gem install ceedling
ceedling new stspin32g4_test
```

### 运行测试

```bash
ceedling test:all
```

## 测试覆盖目标

- 电机控制算法 (FOC / 六步换相)
- PID 控制器
- 通信协议解析
- 传感器数据滤波
- 故障检测 & 保护逻辑

# Mechanical / 3D 模型

STSPIN32G4 电机控制板的外壳和结构件设计。

## 目录

```
mechanical/
├── README.md        # 本文件
└── models/          # 3D 模型文件 (*.step, *.stl, *.stp)
```

## 计划内容

| 模型 | 格式 | 说明 |
|---|---|---|
| PCB 3D 模型 | `.step` / `.stp` | 从 Altium 导出 PCB 3D 模型 |
| 外壳 / 底座 | `.step` / `.stp` | 亚克力 / 3D 打印外壳 |
| 散热器 | `.step` / `.stp` | MOSFET 散热器 (如需要) |
| 固定螺丝 | `.step` / `.stp` | M3 铜柱 / 螺丝孔 |

## 3D 模型来源

1. **Altium Designer** → File → Export → STEP 3D 导出 PCB 模型
2. **各器件厂商官网** → 下载元器件的 STEP 封装模型
3. **自行建模** → Fusion 360 / SolidWorks / FreeCAD

## 参考尺寸

> 待 PCB Layout 完成后获取实际尺寸

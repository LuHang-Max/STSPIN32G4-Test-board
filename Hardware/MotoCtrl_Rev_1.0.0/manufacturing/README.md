# Manufacturing Outputs

PCB 生产制造输出文件，按版本管理。

## 目录说明

| 编号 | 目录 | 内容 |
|---|---|---|
| 1 | `1_Gerber/` | Gerber 光绘文件 (.GTL, .GBL, .GTS, .GBS, .GTO, .GBO, .DRL 等) |
| 2 | `2_BOM/` | BOM 物料清单 (.xlsx, .csv) |
| 3 | `3_PickPlace/` | 贴片坐标文件 (Pick & Place) |

## 输出规范

- 每次打样 / 生产前，将对应版本的制造文件放入以上目录
- 文件命名建议包含日期：`MotoCtrl_Rev1.0_2026-06-25.zip`
- Gerber 文件已在 `.gitignore` 中被忽略，如需版本管理请单独存放或使用 Git LFS
- 如需提交制造文件到 Git，请取消 `.gitignore` 中对应规则

## 生成方式

在 Altium Designer 中：
1. **Gerber**: File → Fabrication Outputs → Gerber Files
2. **BOM**: Reports → Bill of Materials → Export
3. **Pick & Place**: File → Assembly Outputs → Generates pick and place files

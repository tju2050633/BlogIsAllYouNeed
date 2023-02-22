## vscode选择了python3.8.9解释器，pip3安装了torch等库且依赖正确、版本最新

**错误提示**：
> Traceback (most recent call last):
>   File "...", line 1 in <module\>
>     import torch
> ImportError: No module named torch

---

**分析**：
排除pip方面问题（安装了最新版本库且pip3 check没问题），排除代码问题（仅一句import torch也错），是本地环境问题。
注意Code Runner插件对Python很多时候会出问题。

---

**解决**：
右键“在终端中运行Python文件”。

Created On : 2023-02-22
Last Modified : 2023-02-22
## 使用了UnityEditor下的类，如using UnityEditor.Animations中的AnimatorController，打包时报错

**错误提示**：
> The type or namespace name 'AnimatorController' could not be found (are you missing a using directive or an assembly reference?)

---

**分析**：
看报错信息猜测是打包时未能识别使用命名空间语句
```
using UnityEditor.Animations;
```
UnityEditor下的类，打包时不会被打包进去，所以报错。该命名空间下的类，只能在Unity编辑器中使用。

---

**解决**：
Copilot方案：
在打包时，将使用了UnityEditor下的类的脚本，放到Editor文件夹下，这样打包时就不会报错了。（推荐）

B站视频及LightingTheDungeon方案：
删掉using UnityEditor.Animations;语句，将AnimatorController类型改为RuntimeAnimatorController类型，这样打包时就不会报错了。

Created On : 2023-02-21
Last Modified : 2023-02-21
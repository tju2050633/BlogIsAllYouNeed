## Unity做2D游戏（无论2D还是3D模板），都用canvas来做UI，但是canvas的尺寸设置不同，会导致UI显示不同。

**错误情况**：
- 游戏全屏时，UI显示不全或边上有空白
- 美术素材适配出错或比例失调

---

**解决**：
在canvas的面板里设置Canvas Scaler如下：
```
缩放模式    屏幕大小缩放
参考分辨率  X: 1920 Y: 1080
屏幕匹配模式 Match Width Or Height
匹配        拉到高度（1）
每单位参考像素  100
```

可能出现UI设计与屏幕尺寸不适配而出现空白边，需设置摄像机的纯色填充。

Created On : 2023-02-21
Last Modified : 2023-02-21
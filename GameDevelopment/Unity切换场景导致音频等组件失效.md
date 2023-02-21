## Unity中切换场景常常需要切换BGM，但音频组件突然失效。

**错误提示**：
> MissingReferenceException: The object of type 'AudioSource' has been destroyed but you are still trying to access it.
> Your script should either check if it is null or you should not destroy the object.

---

**分析**：
切换场景时，场景中的对象会被销毁，音频组件是挂在空物体上的，所以会被销毁。所以BGM消失不是脚本的问题。但需要在脚本中设置该组件在切换场景时不被销毁。

---

**解决**：
Copilot方案：
在音频组件的面板中，勾选`Dont Destroy On Load`。

管哥教的方案：
AduioManager.cs脚本中在`Awake()`方法中添加：
```
DontDestroyOnLoad(this.gameObject);
```

LightingTheDungeon中采用的是音乐、音效分开两个组件，所以是两句：
```
DontDestroyOnLoad(audio);
DontDestroyOnLoad(sound);
```

具体看情况而定，总之是在切换场景时不销毁音频组件。

Created On : 2023-02-21
Last Modified : 2023-02-21
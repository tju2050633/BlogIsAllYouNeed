## Unity中EventSystem物体被删除后，鼠标点击无效。

**分析**：
EventSystem是游戏处理键鼠等输入的对象，负责将用户输入传递给其他对象。删除后就无法进行点击按钮等操作。

---

**解决**：

重新创建EventSystem物体，要包含的组件：

1. EventSystem：这是EventSystem的主要组件，用于处理和分发用户输入事件。它通常作为一个单例存在于场景中，你可以通过在场景中添加一个空的GameObject并添加EventSystem组件来创建一个EventSystem实例。
2. StandaloneInputModule：这个组件负责处理来自鼠标、键盘等输入设备的事件，并将它们传递给EventSystem进行处理。它是EventSystem的默认输入模块，可以通过向EventSystem对象添加该组件来启用鼠标和键盘输入。



Created On : 2023-05-22
Last Modified : 2023-05-22
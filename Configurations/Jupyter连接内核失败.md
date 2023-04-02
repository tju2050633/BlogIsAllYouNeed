## Jupyter文件选择了Python3.8.9解释器，运行第一个cell时报错连接内核失败

**错误提示**：
> 内核启动失败，因为无法从
> "..."导入"filefind"。
> 来源：Jupyter(扩展)

---

**分析**：
之前看d2l时Jupyter正常运行，这段时间为了跑VRGNet改了很多库版本。
询问ChatGPT得知可能的解决方法：1.检查Jupyter库依赖性 2.重启电脑 3.检查网络设置

---

**解决**：
更新traitlets等jupyter依赖的库，直到pip3 check无误。

Created On : 2023-02-22
Last Modified : 2023-02-22
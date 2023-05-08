## 卸载Xcode后，除了Mac自带的命令行工具都无法使用，如pip3, python, gcc等。

**错误提示**：
> xcrun: error: active developer path ("/Applications/Xcode.app/Contents/Developer") does not exist.
>
> Use `sudo xcode-select --switch path/to/Xcode.app` to specify the Xcode that you wish to use for command line developer tools, or use `xcode-select --install` to install the standalone command line developer tools. 
>
> See `man xcode-select` for more details.

---

**分析**：

这些命令行工具需要Command Line Tools ，一套基于 Xcode 的开发工具，而该工具依托于Xcode，卸载Xcode后会出现“Xcode工具链路径丢失”的错误。

xcode-select有命令可以重置路径。

---

**解决**：

首先确定安装了Command Line Tools。

```
xcode-select --install
```

提示

> xcode-select: error: command line tools are already installed, use "Software Update" to install updates

则已经安装。然后重置其路径。

```
sudo xcode-select --reset
```

输入密码后即可。现在使用命令行工具验证可用，问题解决。

Created On : 2023-04-11
Last Modified : 2023-04-11
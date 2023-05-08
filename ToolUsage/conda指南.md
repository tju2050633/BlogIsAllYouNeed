## conda常用命令

---

1. 创建 conda 环境：

```
conda create -n <env_name> python=<python_version>
```

这个命令将创建一个名为 `<env_name>` 的 conda 环境，并指定所需的 Python 版本 `<python_version>`。

2. 激活 conda 环境：

```
conda activate <env_name>
```

这个命令将激活名为 `<env_name>` 的 conda 环境，使得在终端或命令行窗口中使用该环境下的软件包和 Python 解释器。

3. 在 conda 环境中安装软件包：

```
conda install <package_name>
```

这个命令将在当前激活的 conda 环境中安装名为 `<package_name>` 的软件包。

4. 在 conda 环境中更新软件包：

```
conda update <package_name>
```

这个命令将更新当前激活的 conda 环境中的名为 `<package_name>` 的软件包。

5. 在 conda 环境中删除软件包：

```
conda remove <package_name>
```

这个命令将从当前激活的 conda 环境中删除名为 `<package_name>` 的软件包。

6. 查看当前环境中安装的软件包：

```
conda list
```

这个命令将列出当前激活的 conda 环境中安装的所有软件包。

7. 查看所有可用的 conda 环境：

```
conda info --envs
```

这个命令将列出系统中所有已创建的 conda 环境。

8. 切换到系统默认环境：

```
conda deactivate
```

这个命令将取消激活当前的 conda 环境，切换回系统默认环境。

Created On : 2023-04-22
Last Modified : 2023-04-22
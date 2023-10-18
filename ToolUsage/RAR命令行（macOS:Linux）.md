## macOS/Linux下用命令行运行RAR

---

- 安装rar

```bash
brew install rar
```

- 验证安装

```bash
rar
```

- 压缩命令
  - a：添加压缩文件
  - -r：递归压缩文件夹内所有文件
  - 文件夹后加/
  - 文件指定文件名
  - 默认输出在当前目录
  - -x排除不压缩的文件和文件夹

```sh
rar a -r archive.rar folder/ file.txt
```

- 解压命令
  - 解压到当前目录（可能生成多个文件）

```bash
unrar x archive.rar
```





Created On : 2023-10-18
Last Modified : 2023-10-18
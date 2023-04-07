
## 1. 安装git命令行工具

mac下应该是homebrew，略

## 2. 创建私钥公钥，关联本地终端和远程仓库

### 2.1 配置git中的用户名和邮箱

```
git config --global user.name "your name"
git config --global user.email "your email"
```

### 2.2 生成ssh key

```
ssh-keygen -t rsa -C "your email"
```

一路回车，使用默认命名 id_rsa（私钥） 和 id_rsa.pub（公钥）

### 2.3 复制公钥

打开id_rsa.pub，复制里面的内容，添加到github的ssh key中

```
cat ~/.ssh/id_rsa.pub
```

### 2.4 粘贴到GitHub

- 打开GitHub主页
- 右上角“Settings”>“SSH and GPG keys”>“New SSH key”>“Paste”
- 将公钥粘贴到key中，Title随便填，点击“Add SSH key”

## 3. 创建远程仓库，并将本地仓库上传

- GitHub上创建空仓库
- cd 到本地仓库
- 初始化本地仓库：```git init```
- 关联本地仓库和远程仓库：```git remote add origin git@github.com:your_username/your_repository.git```
- 将本地仓库上传到远程仓库：
  - ```git add .```
  - ```git commit -m "Initial commit"```
  - ```git push -u origin master```

**修改本地仓库后，需要重新commit一下再push**



经常遇到的报错：

- main和master分不清。建议git branch查一下，远程一般默认是main，本地本来默认master现在改成main了(git config --global init.defaultBranch main)。不同名就改一下。远程点按钮改名，本地：git branch -m <old-branch-name> <new-branch-name>

- fatal: You have not concluded your merge (MERGE_HEAD exists).
  Please, commit your changes before you merge.没有完成提交。
  1. git commit -m "update"

- 没有拉取最新远程仓库。
  1. git fetch origin
  2. git merge origin/master


Created On : 2023-03-31
Last Modified : 2023-04-07
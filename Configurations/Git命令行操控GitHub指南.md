
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



---

## **实验记录更新**



#### clone远程仓库后操作

1. 服务器上新建repo，clone远程仓库到本地：

```
git clone git@github.com:tju2050633/test.git
```

2. 别忘了先cd进test目录！
3. 查看当前本地repo状态：

```
git status
```

> On branch main
>
> Your branch is up to date with 'origin/main'.

```
git branch
```

> \* main

```
git remote
```

> origin



显示了当前本地repo有main分支且处于main分支上。

默认应该是master的，用以下命令设置默认创建的分支为main：

``` 
$ git config --global init.defaultBranch main
```

与之关联的远程仓库的代指默认名称origin，有默认的remote是因为本地repo是clone下来的。之后的将本地目录新建为repo会展示怎么手动操作remote。

4. 拉取最新远程仓库：

首先做查看工作，用 `git branch` 命令查看所有分支，并使用 `git checkout` 命令切换到你要更新的分支。如main分支。以及查看远程仓库，使用 `git remote -v` 命令查看当前 Git 仓库中定义的所有远程仓库，并查看它们的 URL 和名称。你也可以使用 `git branch -r` 命令查看远程分支的列表。

查看最新状态，确定是否要更新。使用 `git fetch` 命令从远程仓库中获取最新的提交记录（如果没有需要更新的则终端无输出），并在本地仓库中创建一个指向远程分支的指针。你可以使用 `git log origin/main` 命令查看远程分支的最新提交记录。

解决合并冲突。使用 `git status` 命令查看当前分支的状态，并使用 `git diff` 命令查看冲突的详细信息。你需要手动编辑代码来解决冲突，并使用 `git add` 和 `git commit` 命令提交更改。

拉取命令：

``` 
$ git pull origin main
```

5. 推送本地更改

首先做查看工作，检查branch、remote、status，同上。

提交本地更改。

将更改添加到暂存区命令：（.为所有文件，可以指定文件路径）

```
git add .
```

提交更改命令：（提交消息要指定，不然git会打开vim编辑器，麻烦。提交消息为空还会报错`Aborting commit due to empty commit message.`）

```
git commit -m "update"
```

拉取最新远程仓库。如果远程仓库有更改，而尚未同步到本地仓库，则push时会报错：

>! [rejected]        main -> main (fetch first)
>error: failed to push some refs to 'github.com:tju2050633/test.git'
>hint: Updates were rejected because the remote contains work that you do
>hint: not have locally. This is usually caused by another repository pushing
>hint: to the same ref. **You may want to first integrate the remote changes**
>**hint: (e.g., 'git pull ...') before pushing again.**
>hint: See the 'Note about fast-forwards' in 'git push --help' for details.

先拉取远程更改：

```
git pull origin main
```

此时会发现文件里出现一些诡异的字符。`<<<<<<< HEAD` 标记表示你本地的更改，`=======` 标记表示本地和远程仓库之间的分割线，`>>>>>>>` 标记表示远程仓库的更改。需要手动编辑解决这些冲突。解决完毕后，使用 `git add` 命令将修改后的文件添加到 Git 暂存区中，然后使用 `git commit` 命令将修改后的文件提交到 Git 仓库中。最后push到远程仓库。

推送命令：

``` 
$ git push origin main
```

---

## 新建空的远程仓库，然后git初始化本地目录并上传远程仓库



1. 第一步还是cd进该目录！
2. 初始化目录为本地仓库：

``` 
git init
```

终端输出：

> Initialized empty Git repository in /Users/guolianglu/Desktop/test/.git/

3. 此时用`git status`,`git branch`,`git remote`查看状态，本地仓库有一个main分支，没有remote，有一些文件未追踪（Untracked files）
4. 添加远程仓库URL：

``` 
$ git remote add origin git@github.com:tju2050633/test.git
```

5. `git add.`和`git commit -m "update"`命令将更改添加到暂存区（追踪文件）并提交。

6. 推送

先拉取最新仓库（即使是空的）

当使用 `git pull` 命令将两个没有共同祖先的分支进行合并时，可能会遇到 `fatal: refusing to merge unrelated histories` 错误。这通常是由于本地仓库和远程仓库的历史记录不同步导致的。

这样拉取远程代码：

``` 
git fetch origin
```

合并本地仓库和远程仓库的代码：

``` 
git merge origin/main --allow-unrelated-histories -m "fetch"
```

推送：`-u` 参数表示将本地分支与远程分支关联起来

```
$ git push -u origin main
```





Created On : 2023-03-31
Last Modified : 2023-04-08
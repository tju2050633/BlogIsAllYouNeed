4. Git Rebase

   Rebase是另一个合并分支的方法：取出一系列的提交记录，“复制”它们，然后在另外一个地方逐个的放下去。

   

   Rebase 的优势就是可以创造更「线性」的提交历史。

   

   使用`git rebase branch_name`（其中branch_name是当前分支要合并“去”的分支名）「合并」两个分支。

   

   此时当前分支原来所在的提交记录依然存在（C3），但当前分支已经移动到rebase的分支（main）的子节点去了。然而rebase的分支还没有更新。

   

   如果有多个分支，则创建新提交记录接在下面；如果分支已经是最新版本，则是将分支指向目标提交记录。

   

   ![](img/base-rebase-1.png)

   

   如果要「rebase」的分支是当前分支的子节点，Git 什么都不用做，只是把当前分支移动到那个分支所指的提交记录上。

   

   ![](img/base-rebase-2.png)

   通关记录：（初始状态：C0，C1（main*））

   
   
   ![](img/base-rebase-3.png)
# gitCookBook

本项目是一个开源爱好者对git操作的归档。

[Git 的入门使用 | 开源指北 (gitee.io)](https://oschina.gitee.io/opensource-guide/git_tutorial/Git 入门（初级篇）/Git 的入门使用/#commit-提交到本地存储库)

[git reset & checkout 详解 - 掘金 (juejin.cn)](https://juejin.cn/post/7040638672584048671)

# ssh密匙制作

[生成/添加SSH公钥 - Gitee.com](https://gitee.com/help/articles/4181)

存在User目录下吧。

把pub公匙配置给hub账号

# 初始化本地仓库并推送到远程端

## 本地仓库初始化：

~~~matlab
git init    %初始化本地仓库 cmd中%时注释符
git branch  -M lctee/lchub %[-M] 重命名默认分支
git add *   %追踪所有工作区文件到暂存区中
git commit -m [message]    %保存本次暂存区所有修改，作为仓库的最新版本
~~~

## 推送到到远程仓库

若远程仓库为空，为根据['master'] 创建初始默认分支

~~~cpp
git remote add [gitee/github] http/ssh.git  %新建远程仓库
git push -u lchub github 'master'  %推送[本地分支]到[远程仓库]的[远程分支]，并设置好此本地分支的默认远程分支 
~~~

## 多分支推送不同仓库与更新

~~~matlab
git branch lctee  %创建新的分支
git checkout lctee %切换分支

%设置此分支连接远程分支
git branch --track %启动分支追踪模式
git branch --set-upstream-to gitee/master  %设定当前分支的追踪远程分支

%拉取远程分支，并生成分支合并(远程与本地)工作流，
git pull gitee [master] : [lctee]   %设定好当前分支和追踪分支后，后两个参数可以不填
%审阅代码冲突
%合并完成后，可以向远程push了,% <远程主机名> <本地commit>:<远程分支名> 同名可省略远程远程分支，否则无法省略
git push -u gitee lctee[:'master']  
~~~

![image-20230415134158863](https://s2.loli.net/2023/04/15/bym8UlS4Xqz5Hpu.png)

其中，push内容为本次的commit。



# 仓库同步命令手册

## 本地仓库管理 git add/commit

* `git add *`为commit缓冲区添加追踪文件
* `gir rm xx` 为commit缓冲区添加文件删除事件
* `git commit -m [message]` 提取缓冲区，生成push源。-m参数传入推送消息。
* `git commit -a * -m [message]` -a参数调用add程序。
* git restore/reset/checkout :版本回滚，见下

![image-20230415143941163](C:\Users\yceachan\AppData\Roaming\Typora\typora-user-images\image-20230415143941163.png)

![image-20230415144246962](C:\Users\yceachan\AppData\Roaming\Typora\typora-user-images\image-20230415144246962.png)

## 远程仓库管理 git remote

[Git - 远程仓库的使用 (git-scm.com)](https://git-scm.com/book/zh/v2/Git-基础-远程仓库的使用)

* `git remote show [gitee]`   展示远程仓库信息  

![image-20230415135039561](https://s2.loli.net/2023/04/15/TdQjqFXMVgHs7v9.png)

`gir remote add/rm/rename` 增删改远程仓库

## 分支管理     git branch checkout

* `git branch` 查看仓库下所有分支
* `git chechkout [branch]` 切换当前选中分支

* `git branch lchub` : 新建本地分支
* `git branch -M [old] newbreanch` 重命名本地分支，当old缺省时，修改当前分支

* `git branch --track/--untrack` 配置追踪模式
* `git branch --set-upstream-to github/master` 配置当前分支的追逐分支————pull时拉取的分支

## 分支拉取合并 git fetch/pull

**拉取分支最近一次修改事件**

`git fetch [github master]` 仅拉取文件，不执行合并工作流 

`git merge` 合并，略

`git pull [github master]` 拉取并合并，随后审阅代码冲突

在追踪分支配置好后，此分支以后的pull无需填写 [github master]参数

配置方式有二：

* `git push -u gihub lchub[:master]` 在初始化远程分支时使用 -u追踪上。
* `git branch --set-upstream-to github/master ` 使用分支管理追踪上。

## 分支推送 git push

[git-push(1)](file:///C:/Program Files/Git/mingw64/share/doc/git-doc/git-push.html)

**推送并设置'git push'追踪分支**

`git push -u gitee lcgitee:master`  <开启追踪> <远程仓库>  <本地分支>[:<远程分支>]

不写远程分支名时，自动推送同名分支。若远程仓库无此分支,自动创建。

![image-20230415145254061](https://s2.loli.net/2023/04/15/ogq9r1fCwJYEBkN.png)

此方法在gitee中仍然不行

在github中,同名分支可以直接 git pull ,git push



# GIT工作模型 工作区 暂存区 版本库

- **工作区：**就是你在电脑里能看到的目录。
- **暂存区：**英文叫 stage 或 index。一般存放在 **.git** 目录下的 index 文件（.git/index）中，所以我们把暂存区有时也叫作索引（index）。
- **版本库：**工作区有一个隐藏目录 **.git**，这个不算工作区，而是 Git 的版本库。

![img](https://www.runoob.com/wp-content/uploads/2015/02/1352126739_7909.jpg)

# 版本控制命令手册

首先要摒弃git是为远程仓库服务的挂念。git的一切命令基于本地的分布式版本控制需求。

## **git add** 

将所选文件添加到暂存区，开始追踪其变更。

## git restore

**git restore --staged  <file_name>**： 将暂存区的修改重新放回工作区（**包括对文件自身的操作，如添加文件、删除文件**）

**git restore <file_name>**：丢弃工作区的修改（**包括对文件自身的操作，如添加文件、删除文件**）

从暂存区弹出文件

## git checkout 

git checkout 有两个特性：

- 切换分支：不带具体的文件路径时，用于修改head当前指向的分支
- 检出文件：带具体的文件路径时，从指定的respository 或者 stage 中恢复文件

若FILE不在暂存区中，回滚到最近的分支版本（respository ,commit）

若FILE在暂存区中，回滚到add 如暂存区前的状态(stage,add)

**总之，就是让这个工作区文件回滚到最近一次`git commit`或`git add`时的状态。**

## git reset  

操作对象：项目的当前commit(HEAD指针)

- commit：是指respoistory中每次保存（提交）后的结果，指向一个完整的版本记录
- head：是一个指针，代表当前正在操纵的版本（commit），可以指向feature、master等有名分支，也只指向某一commit id 直接代表的版本

，git reset 实际上就是在修改**head指向的commi**t，所以相当于会将**head指向repository中特定的commit**。同时根据修改head后，**是否级联修改stage、workspace，**可进一步的细分成三种模式hard、sort、mixed（默认），如下图所示：

![git4.png](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/048b2733d7054c99a18fc402b9bfba40~tplv-k3u1fbpfcp-zoom-in-crop-mark:4536:0:0:0.awebp?)

`git reset --hard github/master` 回滚到远程仓库当前版本



### --soft

会重置repository，但保留stage、workspace中的改动

用法：合并两次commit——：仅将仓库的版本标记回退，而不撤销任何修改。

然后分不同此commit做出的修改可一并打包为一次commit。



### --mixed

可以重置缓冲区。方便回滚追踪逻辑



### --hard

会重置工作区，用于项目的版本回滚。




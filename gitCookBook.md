# gitCookBook

本项目是开源爱好者笔者对git操作的归档。

# ssh密匙制作

[生成/添加SSH公钥 - Gitee.com](https://gitee.com/help/articles/4181)

存在User目录下吧。

把pub公匙配置给hub账号

# 初始化本地仓库并推送到远程端

## 本地仓库初始化：

~~~matlab
git init    %初始化本地仓库 cmd中%时注释符
git branch  -M lctee/lchub %[-M] 重命名默认分支
git add *   %将本地文件添加到push缓冲区
git commit -m [message]    %提取缓冲区，生成推送源 -[m]为推送消息 
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
%合并完成后，可以向远程push了,% <远程主机名> <本地分支名>:<远程分支名> 同名可省略远程远程分支，否则无法省略
git push -u gitee lctee[:'master']  
~~~

![image-20230415134158863](https://s2.loli.net/2023/04/15/bym8UlS4Xqz5Hpu.png)

其中，本地分支名可用HEAD选中分支



# 常用命令手册

## 本地仓库管理 git add/commit

* `git add *`为commit缓冲区添加推送文件事件
* `gir rm xx` 为commit缓冲区添加删除文件事件
* `git commit -m [message]` 提取缓冲区，生成push源。-m参数传入推送消息。
* `git commit -a * -m [message]` -a参数调用add程序。

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

## 冲突审阅 -vim

待更新
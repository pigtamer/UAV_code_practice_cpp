# Git 笔记

这是关于git协作中切换分支, 拉取分支, 同步到远程仓库的笔记.
主要用于最基本的多人协作.

下面代码中所有被尖括号包含的内容随用户而异. 替换时删除尖括号.

> 参考了链接: [廖雪峰的Git教程](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)

## 初始化仓库
    
1. 本地初始化
    ```bash
    git init
    ```

2. 本地添加更改

3. 本地提交更改
    ```bash
    git commit -m "<message>"
    ```

4. 本地查看更改历史
    ```bash
    git log
    ```
    需要说明一下这个命令的输出结果:

    ```bash
    commit 98c8ecae65f84a84fdc6c265a3f8a880b11095c8 (HEAD -> algo, origin/algo)
    Author: PigTamer <cygee99@gmail.com>
    Date:   Fri Jan 26 23:33:32 2018 +0800

        fundamental api for video io without qt involved

    commit cee805d891add7c25995f10dbf4bf898a52789c6
    Author: PigTamer <cygee99@gmail.com>
    Date:   Fri Jan 26 18:24:47 2018 +0800

        force push
    ```

    上面显示了两次提交历史. commit 后面的一长串代码唯一代表了分支中的此版本, 这个代码在之后切换到旧版本时有用.

    在每个date下面的文字是本次提交对应的消息, 由用户写入.

5. 本地回溯到旧版本
    ``` bash 
    git checkout <版本代码的前五位>
    ```

    
## 设定远程端地址

1. 添加

    ``` bash
    git remote add origin <URL>.git 
    ```
    其中 <URL> 是想要的git仓库的master主分支地址.

2. 查看
    要查看当前拥有的远程端, 使用
    ``` bash
    git remote -v
    ```
    这个命令会列出当前所在的git仓库, 仓库的分支, 以及相关的权限信息

3. 删除
    如果设定不对, 比如设到了其他的仓库, 用删除命令删除本地仓库:

    ```bash
    git remote remove origin 
    ```

    上面的几条命令中, origin "原点" 的名称可以用自己喜欢的名称取代. 但要注意, 设定之后在今后的操作中都要使用这个名称作为git仓库的原点. 比如 origin master 将表示这个仓库的master分支地址.

    每个仓库有且只有一个master主分支, 它不可重命名.

## 与远程同步

1. 从远程端抓取

    ``` bash 
    git pull <分支地址>
    ```

    比如 git pull origin master 将把远程端master的版本抓取到本地.
    而 git pull origin gui 将把"图形界面"分支拉到本地



2. 将本地更改推到远程

    首先一定要切换到你想要推送到的那个分支:

    ```bash
    git checkout <我要的分支地址>
    ```

    如果要推到图形界面的修改, 那么使用 git checkout gui
    
    推到算法修改, 使用git checkout algo

    ```bash
    git push --all
    ```

    或者推到分支, 比如git push origin master会推到主分支


3. 分支修改和融合

    还在研究中~ 可能会开个github小号加上虚拟机自己试验吧2333.


# Hexo搭建博客

---------

#### 介绍

> 该笔记记载我使用Hexo在Github上搭建博客的过程

-----

#### 预备知识

> - 明白Git 命令
> - 了解Node.js

-----

#### 环境准备

> - Git
> - Node.js

---

#### 命令

> 初始化
>
> ```java
> hexo init blog
> cd blog
> npm install
> ```
>
> 发布文章
>
> ```java
> hexo new 文章名
> ```
>
> 将文章变为静态资源，用于部署网站
>
> ```java
> hexo generate
> ```
>
> 启动服务器
>
> ```java
> hexo server
> ```
>
> 将网站部署到Github
>
> ```java
> hexo deploy
> ```
>
> 

------

#### 文件夹目录

> - blog/source/_posts  存放文章
> - blog/__config.yml  网站配置_
> - blog/public 存放静态资源

-----

#### 需要修改的网站配置

> 修改__config.yml_文件  **注意点    : 后记得空格**
>
> ```java
> #Deployment
> deploy:
>     type: git
>     repo: 仓库地址
> 	branch: 仓库分支名
> ```

-----

#### 建议修改的配置

> ```java
> #site 下面的内容
>  title: xxxx
>    ....
> ```
>
> ```javav
> #writing
> post_asset_folder: true
> ```

------------

#### 结束语

更详细的可以查看官网--[学习如何使用Hexo搭建免费博客](https://hexo.io/zh-cn/docs/)


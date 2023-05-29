# VMWare
- - 桥接模式
- NAT模式
- 主机模式

# Linux（一切皆为文件）

## 目录结构

- bin  sbin（指令集合）
- dev media（硬件）
- home（用户）
- etc  boot（配置）
- user opt（软件）
- lib64  lib（动态链接库）
- mnt（装载）
- proc srv  sys
- run
- root
- var

## 命令

### 基础

- cd   进入目录

- ls     

- pwd  显示当前路径

  

### 通用

- rm  pathname  删除
  1. 若需要删除目录,加上  -rf  :  rm  -rf pathname  
- mv  oldpathname   newpathname 移动

### 目录

- mkdir  pathname  新增目录

### 文件

- touch pathname  新增文件
- cat  pathname  查看文件内容
- more   pathname (分页查询文件内容)
- vi/vim  pathname  编辑文件 
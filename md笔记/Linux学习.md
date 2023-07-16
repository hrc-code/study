
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

进入目录
```git 
cd 目录名
```
显示目录的结构  
```git
ls
```
显示当前路径
```git
pwd
```
删除文件
```git
rm 文件路径
```

移动文件和目录
```git
mv  移动的目录或文件路径 目的地路径
```
### 目录
新增目录
```git
mkdir 新目录名
```
删除目录
```git
rm -rf 目录路径
```
### 文件
新增文件
touch pathname  
查看文件内容
```git
cat 文件名
head 文件名
tail 文件名
```
分页查询文件内容
```git
more 文件名
```
修改文件基本属性

- chmod
- chown
- chgrp
```java
r-4 w-2 x-1 chomd 777 文件路径 =chomd -u=rwx -g=rwx -o=rwx 文件路径
chown 新主人 文件路径  
chgrp 新属组  文件路径    == chown :新属组 文件路径 
```
## vim

## 命令模式

- 进入编辑
	- i
	- o
	- a
- 删除
   - dd  删除光标所在行
   - ndd  删除当前行开始连续的n行
   - n,md  删除从n行到m行
   - n,$d  删除从n行到末尾	
- 撤销
	- uu 撤销	
## 底线命令模式

## 编辑模式

## 磁盘管理

- df
- du
- fdisk
 - su 切换用户
- passwd 修改用户密码
- mount 挂载设备  unmount 卸载设备

-----------

#### tree命令

> ```java
> tree -L 需要显示的子集目录
> ```
>
> 

----


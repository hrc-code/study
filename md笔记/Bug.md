# Bug

---------

#### 介绍

积累在开发中所遇到的Bug以及解决方案

----------

#### IDEA

> - IDEA初始化SpringBoot工程失败
>   - 可以将Server URL改为https://start.springboot.io 或者https://start.aliyun.com

----------

#### JDK

---

为jdk8以后的jdk添加jre文件夹

```
bin\jlink.exe --module-path jmods --add-modules java.desktop --output jre
```


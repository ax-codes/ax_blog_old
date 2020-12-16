---
title: windows docker挂载文件夹不起作用问题
date: 2018/12/21 20:00:00
categories: 技术
toc: True
tags: [docker,windows,开发工具/插件]
---

### 前言
windows docker挂载文件夹不起作用问题
例如:
```
docker run -ti  --security-opt seccomp=unconfined   -p 127.0.0.1:60522:22 -v /D/build:/build centos:6 /bin/bash
```
然后进入容器发现/build是空的

### 解决
1:windows 的 docker 映射文件夹只能映射"C:\Users" 下的路径,如果觉得文件都放 C:\Users 不好的话,我们可以创建link,把link放到C:\Users下
```shell
mklink /J "C:\Users\链接名称" "D:\build\源文件夹名称"
```
2:注意在windows里盘符要用小写,不能用大写(git bash 进入 /c/Users/ pwd的路径),不然docker容器会识别不到路径
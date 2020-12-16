---
title: windows 宿主机器ssh连接到docker镜像
date: 2018/12/26 20:00:00
categories: 技术
toc: True
tags: [docker,windows]
---


### 前言
系统环境:windows7
docker版本:Docker version 18.03.0-ce, build 0520e24302
情景:使用docker的一个镜像专门作为编译和linux开发环境

### 步骤
1:启动docker ssh 连接到docker虚拟机 
```shell
docker-machine ssh default
```
2:启动镜像 因为我们是在docker虚拟机启动的容器,所以此时容器对应的主机就是docker虚拟机,所以60522 表示虚拟机端口,22 表示容器端口
```shell
docker run -ti   -p 127.0.0.1：60522:22   centos:6 /bin/bash
```
此时我们在宿主机器查看60522这个端口是没有运行的,因为上面已经说了启动60522端口的机器是虚拟机
3:查看虚拟机ip
```shell
docker-machine ip default
```
一般情况下这个地址是192.168.99.100
宿主机器ping 192.168.99.100 发现可以ping通
4:在宿主机器ssh连接虚拟机的60522端口,对应的连到的就是启动的镜像的ssh端口
```shell
ssh gx@192.168.99.100 -p 60522
```

### 总结
流程:宿主机器->虚拟机->容器
docker虚拟机是可以跟所有的宿主机器ping通的
mac因为是直接在宿主机器启动的镜像,所以对应的映射端口的机器就是宿主机器
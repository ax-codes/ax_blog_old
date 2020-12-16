---
title: Clion 远程构建和部署排除了路径重置。无法读取CMakeCache.txt问题
date: 2018/12/24 20:00:00
categories: 技术
toc: True
tags: [docker,c语言,c++,开发工具/插件]
---

### 前言
Clion 远程构建和部署排除了路径重置。无法读取CMakeCache.txt问题

### 报错日志
```shell
[2018-12-23 21:24] Excluded path '/Users/ax/myproject/cmake-build-remote-debug/CMakeCache.txt'
[2018-12-23 21:24] 1 item excluded
[2018-12-23 21:24] No files or folders found to process
```

### 原因
可能是因为同时使用了两个相同的账号在同时使用，比如clion配置的ssh的账号使用的是root然而root现在正在使用
情景：宿主机器在docker远程编译，docker容器正在登陆root账号，然后clion 也在使用远程的root账号

### 解决
在远程机器新建一个专门远程编译的账号，然后clion使用该账号进行远程编译,或者在linux切换一个账号(su gx),clion就可以使用root了,本人更偏向于新建一个专门编译的账号
使用root新建账号
```shell
useradd gx #新增gx账号
echo "123456" |passwd --stdin gx #设置gx账号密码
```
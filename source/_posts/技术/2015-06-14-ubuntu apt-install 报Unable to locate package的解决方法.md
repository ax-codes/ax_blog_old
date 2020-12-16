---
title: ubuntu apt-install 报Unable to locate package的解决方法
date: 2015/06/14 08:00:00
categories: 技术
toc: True
tags: linux
---
### 前言
ubuntu apt-install 报Unable to locate package的解决方法

### 情景
使用新买的阿里云ubuntu服务器用apt-get install的时候报错

### 解决方法
执行
```shell
sudo apt-get update
```
然后就可以安装了
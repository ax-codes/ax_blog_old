---
title: linux 设置 root 密码命令
date: 2018/12/24 20:00:00
categories: 技术
toc: True
tags: [docker,linux,开发工具/插件]
---

### 前言
情景：docker 里的 容器root默认是没有密码的,但是ssh的时候是需要密码登录

### 解决
设置root密码为"123456"
```shell
echo "123456" |passwd --stdin root
```

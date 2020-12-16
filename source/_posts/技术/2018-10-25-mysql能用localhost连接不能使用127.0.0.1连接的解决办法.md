---
title: mysql能用localhost连接不能使用127.0.0.1连接的解决办法
date: 2018/10/25 17:00:00
categories: 技术
toc: True
tags: [数据库,开发工具/插件,windows,linux]
---

### 前言
因为用nodejs的mysql


### 解决
1.vim /etc/my.cnf
2.注释skip_networking
3.bind_address=127.0.0.1(没有的话新增) 
4.重启mysql
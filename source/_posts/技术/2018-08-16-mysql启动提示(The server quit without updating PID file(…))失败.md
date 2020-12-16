---
title: mysql启动提示(The server quit without updating PID file(…))失败
date: 2018/08/16 17:43:00
categories: 技术
toc: True
tags: [数据库,开发工具/插件,windows,linux]
---

### 前言
linux启动mysql失败报错:
![1.jpg](1.jpg)

### 解决
```shell
1: /etc/init.d/mysqld start
2: /etc/init.d/mysql start
```
连接mysql 发现连接成功
---
title: mysql ERROR 1018 (HY000) Can't read dir of .xxxx(errno 13)解决方法
date: 2018/12/24 20:00:00
categories: 技术
toc: True
tags: [数据库]
---

### 前言
mysql ERROR 1018 (HY000) Can't read dir of .'xxxx'(errno 13)解决方法

### 报错日志
show tables的时候报这种格式的错误
```shell
ERROR 1018 (HY000): Can't read dir of './dbname/' (errno: 13)
```

### 解决方法
```shell
chown -R mysql:mysql /var/lib/mysql/dbname
```
/var/lib/mysql:是mysql 数据路径(可以搜索数据库名称得到 find / -name dbname;whereis mysql可能没有)
dbname:show tables失败的数据库名称

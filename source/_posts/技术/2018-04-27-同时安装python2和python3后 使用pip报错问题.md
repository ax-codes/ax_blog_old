---
title: 同时安装python2和python3后 使用pip报错问题
date: 2018/04/27 20:00:00
categories: 技术
toc: True
tags: ["python"]
---

### 前言

同时安装 python2 和 python3 后使用 pip 报错问题

python2 pip -V or python3 pip -V

### 报错日志

```
E:\Python27\python2.exe: can't find '__main__' module in 'pip'
```

### 解决方法

在 python2 或者 python3 后面加上 -m
python2 -m pip -V or python3 -m pip -V
表示已模块的方式运行
默认的不用加

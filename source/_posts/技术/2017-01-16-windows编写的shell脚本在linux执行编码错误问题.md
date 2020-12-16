---
title: windows编写的shell脚本在linux执行编码错误问题
date: 2017/01/16 20:00:00
categories: 技术
toc: True
tags: [linux,windows]
---


### 前言
在windwos下用记事本编写了个shell脚本,拿到cygwin下运行没问题,但是拿到linux下运行就出问题


### 报错日志
```shell
./beijingsqm_update.sh: line 13: syntax error near unexpected token `$'\r'
```

### 解决方法
#### 使用vi打开该脚本

#### 设置fileformat(ff) 
```shell
:set ff=unix
```

#### 保存退出
```shell
:wq
```

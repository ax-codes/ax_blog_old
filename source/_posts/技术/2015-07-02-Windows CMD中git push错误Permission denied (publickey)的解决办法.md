---
title: Windows CMD中git push错误Permission denied (publickey)的解决办法
date: 2015/07/02 08:00:00
categories: 技术
toc: True
tags: 开发工具/插件
---
### 前言
Windows CMD中git push错误Permission denied (publickey)但git终端可以的解决办法

### 解决方法
把id_rsa，id_rsa.pub拷贝到git\.ssh目录下,然后重新打开终端push发现成功
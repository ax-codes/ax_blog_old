---
title: linux 下root无法登录ftp问题
date: 2015/06/12 08:00:00
categories: 技术
toc: True
tags: linux
---
### 前言
linux 下root无法登录ftp问题

### 解决
将vim /ect/ftpusers 下的root注释
然后 /ect/init.d/vsftpd restart 即可
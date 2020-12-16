---
title: Docker在windows下无法开启伪终端解决方法
date: 2018/07/09 17:43:00
categories: 技术
toc: True
tags: [docker,windows]
---

### 问题
在windows下面安装了docker以后，运行docker run -it ubuntu /bin/bash失败，提示错误“cannot enable tty mode on non tty input”

### 解决
第一种在命令前面加上winpty
```
winpty docker run -it ubuntu /bin/bash
```

第二种方案更好（为什么自己去感受吧）
```
docker-machine ssh default
docker run -it ubuntu /bin/bash
```
---
title: 在使用pip list时出现DEPRECATION 的解决方法
date: 2015/04/03 08:00:00
categories: 技术
toc: True
tags: python
---
## 在使用pip list时出现DEPRECATION 的解决方法
### windows
在C:\Users\Administrator下建立pip文件夹,在pip下新建pip.ini,添加内容:
```ini
[list]
format=columns
```

### linux
在 ~/pip/pip.conf 配置文件中加入下面的语句
```ini
[list]
format=columns
```
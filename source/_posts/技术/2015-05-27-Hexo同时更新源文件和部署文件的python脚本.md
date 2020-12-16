---
title: Hexo更新源文件和部署文件的python脚本
date: 2015/05/27 08:00:00
categories: 技术
toc: True
tags: [python,开发工具/插件]
---
### 前言
Hexo编译和提交git的python脚本
环境:windows python
脚步存放路径:hexo博客的根目录(执行hexo s或者hexo g的目录)
运行:python update.py(push.py是你的文件名)

### 脚本
```python
import os

print('===开始执行===')
print('===git pull origin master===')
os.system("git pull origin master")
print('===git merge remoter/origin/master===')
os.system("git merge remoter/origin/master")
print('===cd public===')
os.chdir('.\\public')
print('===git pull origin master===')
os.system("git pull origin master")
print('===git merge remoter/origin/master===')
os.system("git merge remoter/origin/master")
print('===执行结束===')
```

### 备注
如果在运行的时候报Permission denied (publickey)这个错误的话,可以这样解决:
把id_rsa，id_rsa.pub拷贝到git\.ssh目录下
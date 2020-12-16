---
title: windows pip install Scrapy 报错问题
date: 2019/01/16 20:00:00
categories: 技术
toc: True
tags: [python,windows]
---


### 前言
环境:windows(64位) python2.7(64位)
安装Scrapy:pip install Scrapy


### 报错日志
```shell
    copying src\twisted\python\test\_deprecatetests.py.3only -> build\lib.win-am
d64-2.7\twisted\python\test
    copying src\twisted\words\im\instancemessenger.glade -> build\lib.win-amd64-
2.7\twisted\words\im
    copying src\twisted\words\xish\xpathparser.g -> build\lib.win-amd64-2.7\twis
ted\words\xish
    running build_ext
    building 'twisted.test.raiser' extension
    error: Microsoft Visual C++ 9.0 is required. Get it from http://aka.ms/vcpyt
hon27

    ----------------------------------------
Command "c:\python27\python.exe -u -c "import setuptools, tokenize;__file__='c:\
\users\\ax\\appdata\\local\\temp\\pip-install-nml_jq\\Twisted\\setup.py';f=getat
tr(tokenize, 'open', open)(__file__);code=f.read().replace('\r\n', '\n');f.close
();exec(compile(code, __file__, 'exec'))" install --record c:\users\ax\appdata\l
ocal\temp\pip-record-xvawb1\install-record.txt --single-version-externally-manag
ed --compile" failed with error code 1 in c:\users\ax\appdata\local\temp\pip-ins
tall-nml_jq\Twisted\
```

### 解决方法
#### 查看安装twisted哪个版本报错
在pip install Scrapy的log里能看到是安装twisted哪个版本报错,如下图
![1.jpg ](1.jpg)

#### 下载twisted
https://www.lfd.uci.edu/~gohlke/pythonlibs/#twisted
直接在页面ctrl+f查询你要安装的版本,如下图
![2.jpg ](2.jpg)

#### 安装twisted
pip install C:\Users\ax\Downloads\Twisted-18.9.0-cp27-cp27m-win_amd64.whl
>C:\Users\ax\Downloads\ 为我的下载路径

#### 重装scrapy
pip install Scrapy
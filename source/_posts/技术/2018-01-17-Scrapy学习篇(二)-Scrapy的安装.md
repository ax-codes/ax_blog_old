---
title: Scrapy学习篇(二)-Scrapy的安装
date: 2018/01/17 20:00:00
categories: 技术
toc: True
tags: [python]
---


### 前言
Scrapy的安装

### Scrapy的安装
#### Windows
```shell
pip install --upgrade pip
pip install Scrapy
```

#### ubuntu
```shell
sudo apt-get install python-dev python-pip libxml2-dev libxslt1-dev zlib1g-dev libffi-dev libssl-dev
sudo pip install scrapy
```

#### macos
```shell
$ sudo pip install virtualenv
$ virtualenv scrapyenv
$ cd scrapyenv
$ source bin/activate
$ pip install Scrapy
```

### 测试
```shell
scrapy version
```

### 备注
如果pip install scrapy失败,可以在博客里搜索"windows pip install Scrapy 报错问题"


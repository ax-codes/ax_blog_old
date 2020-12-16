---
title: Scrapy学习篇(三)-Scrapy的常用命令
date: 2018/01/18 20:00:00
categories: 技术
toc: True
tags: [python]
---


### 前言
Scrapy的命令一般分为两种,一种是全局命令,一种是项目命令
全局命令:可以在使用到Scrapy的任何地方使用
项目命令:只能在项目目录里执行

### 全局命令
#### startproject
```shell
scrapy startproject <project_name>
```
这个命令是scrapy最为常用的命令之一,它将会在当前目录下创建一个名为 <project_name>的项目.
#### settings
```shell
scrapy settings [options]
```
该命令将会输出Scrapy默认设定,当然如果你在项目中运行这个命令将会输出项目的设定值.
#### runspider
```shell
scrapy runspider <spider_file.py>
```
在未创建项目的情况下,运行一个编写在Python文件中的spider.
#### shell
```shell
scrapy shell [url]
```
以给定的URL(如果给出)或者空(没有给出URL)启动Scrapy shell.
例如,scrapy shell http://www.baidu.com将会打开百度URL,
并且启动交互式命令行,可以用来做一些测试.
#### fetch
```shell
scrapy fetch <url>
```
使用Scrapy下载器(downloader)下载给定的URL,并将获取到的内容送到标准输出.简单的来说,就是打印url的html代码.
#### view
```shell
scrapy view <url>
```
在你的默认浏览器中打开给定的URL,并以Scrapy spider获取到的形式展现. 有些时候spider获取到的页面和普通用户看到的并不相同,一些动态加载的内容是看不到的, 因此该命令可以用来检查spider所获取到的页面.
#### version
```shell
scrapy version [-v]
```
输出Scrapy版本.配合 -v 运行时,该命令同时输出Python, Twisted以及平台的信息.


### 项目命令
crawl
```shell
scrapy crawl <spider_name>
```
使用你项目中的spider进行爬取,即启动你的项目.这个命令将会经常用到,我们会在后面的内容中经常使用.
check
```shell
crapy check [-l] <spider>
```
运行contract检查,检查你项目中的错误之处.
list
```shell
scrapy list
```
列出当前项目中所有可用的spider.每行输出一个spider.
genspider
```shell
scrapy genspider [-t template] <name> <domain>
```
在当前项目中创建spider.该方法可以使用提前定义好的模板来生成spider.您也可以自己创建spider的源码文件.

### 总结
常用的命令一般只有startproject和crawl,一个是用来创建项目,一个是用来运行项目.
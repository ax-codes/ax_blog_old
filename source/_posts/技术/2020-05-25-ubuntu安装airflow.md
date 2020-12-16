---
title: ubuntu安装airflow
date: 2020/05/25 20:00:00
categories: 技术
toc: True
tags: [python, 开发工具/插件, 效率工具/插件, 其他工具/插件]
---

### 前言

airflow 是一个工作流功能的任务框架
airflow 官网:http://airflow.apache.org/docs/stable/start.html

### 环境

环境:windows 子 liunx 系统
系统版本:ubuntu 02
python 版本:3.8.2

### 安装

```
# but you can lay foundation somewhere else if you prefer
# (optional)
export AIRFLOW_HOME=~/airflow

# install from pypi using pip
pip install apache-airflow

# initialize the database
airflow initdb

# start the web server, default port is 8080
airflow webserver -p 8080

# start the scheduler
airflow scheduler

# visit localhost:8080 in the browser and enable the example dag in the home page
```

### 报错

#### airflow 安装 psutil 的时候报错

```
Failed building wheel for psutil
error: command 'x86_64-linux-gnu-gcc' failed with exit status 1
```

##### 解决

```
pip install Scrapy
pip install virtualenv
apt-get install python2.7 python2.7-dev or apt-get install python3 python3-dev(根据你对应的python版本)
```

#### airflow 安装 mysql 插件时候报错

```
/bin/sh: 1: mysql_config: not found
```

##### 解决

```
sudo apt-get install libmysqlclient-dev
```

#### python airflow 启动报错

```
ModuleNotFoundError: No module named 'typing_extensions'
```

##### 解决

```
pip install typing_extensions
```

#### airflow webserver -p 8080 运行报错

```
FileNotFoundError: [Errno 2] No such file or directory: 'gunicorn'
```

##### 解决

```shell
sudo apt-get install gunicorn
pip install gunicorn
```

### 备注

将 python3 修改成默认 python 执行

```
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3 150
```

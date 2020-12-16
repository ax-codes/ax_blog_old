---
title: windows安装绿色版mysql的方法
date: 2015/03/30 08:00:00
categories: 技术
toc: True
tags: [数据库,windows,开发工具/插件]
---
### 下载
 下载地址:[https://dev.mysql.com/downloads/mysql/](https://dev.mysql.com/downloads/mysql/)
![下载](1.png)

### 配置
1. 新增环境变量:将解压后的文件的bin路径新增到环境变量

2. 新增my.ini配置文件:解压后在文件根目录新建my.ini文件,并新增内容:
```ini
[client]  
port=3306  
# socket = /data/3306/mysql.sock  
#客户端编码方式，最好和服务端保存一致  
loose-default-character-set=utf8  
  
[mysqld]  
skip-grant-tables  
#user=mysql  
port=3306  
# socket = /data/3306/mysql.sock  
# basedir = /usr/local/mysql  
# datadir = /data/3306/data  
  
#mysql根目录  
basedir=F:\mysql-5.7.21-winx64
#数据文件存放目录  
datadir=F:\mysql-5.7.21-winx64\data  
  
open_files_limit=10240  
  
#服务端的编码方式  
character-set-server=utf8  
  
sql_mode=NO_ENGINE_SUBSTITUTION,STRICT_TRANS_TABLES   
  
[WinMySQLadmin]    
Server=F:\mysql-5.7.21-winx64\bin\mysqld.exe  
```
"F:\mysql-5.7.21-winx64"是我mysql的路径,你需要改成自己的

<font color=red>注意:</font>在win7中时my.ini需要放到bin目录下,然后注册表的内容为
```ini
"C:\Program Files\MySQL\bin\mysqld" MYSQL
```


### 安装mysql
用管理员权限启动cmd后执行:
```shell
mysqld install mysql
```

### 开启服务
用管理员权限启动cmd后执行:
```shell
net start mysql
```
或者直接在windows服务管理界面直接找到mysql服务器右键启动即可

>注意:
报错一:
在这一步开启服务的时候可能会报这一个系统找不到指定文件的错
![报错](2.png)
原因和解决方法:
解压版没有像安装版 那样指定目录，所以需要更改注册表： 
HKEY_LOCAL_MACHINE-SYSTEM-CurrentControlSet-services-mysql(服务名)-ImagePath 更改为："C:\Program Files\MySQL\bin\mysqld" --defaults-file="C:\Program Files\MySQL\my.ini" MYSQL
然后重新启动mysql 应该就可以了

报错二:
在win7启动服务的时候如果报这个错
![报错2](5.png)
我们需要
```bat
mysqld --remove mysql
mysqld --install mysql
mysqld --initialize:这一步如果报错,需要删除mysql根目录下的data文件夹
```

### 查找mysql默认密码
mysq在5.7版本以上为root用户默认生成了一个临时登录密码，该密码是生成在数据目录下的后缀名为.err的文件里;
在my.ini配置文件里我写的数据目录是:
```shell
datadir=F:\mysql-5.7.21-winx64\data
```
进该文件夹搜索.err的文件
![查找](3.jpg)
然后进文件里搜索"password"找到:
![password](4.png)
2JZv<uC&jwtX 即是mysql默认的密码,使用这个密码我们即可登录mysql

### 修改初始密码
首先用默认初始密码登录root
```shell
mysql -uroot -p<br>输入默认密码
```
然后修改
```shell
mysql> set password for 用户名@localhost = password('新密码'); 
mysql> set password for root@localhost = password('123'); 
```
显示Ok标识修改成功,这样我们就可以新增用户和修改用户密码了


### 破解Navicar for mysql方法
使用 PatchNavicat.exe,打开后选择Navicar for mysql安装的路径的navicat.exe即可
[PatchNavicat下载](PatchNavicat.exe)
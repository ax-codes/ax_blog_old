---
title: docker安装mysql
date: 2019/01/17 18:00:00
categories: 技术
toc: True
tags: [docker,数据库]
---

### 前言
docker安装mysql

### 安装
```shell
#这里选择5.6版本,你可以安装其他到版本
docker pull mysql:5.6 
#启动mysql 并且映射本机端口和设置mysql密码
docker run -p 3306:3306 --name mymysql -v $PWD/conf:/etc/mysql/conf.d -v $PWD/logs:/logs -v $PWD/data:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=123456 -d mysql:5.6
```
做完上面两步发现就可以连接到mysql了

### 命令说明
```shell
-p 3306:3306：将容器的 3306 端口映射到主机的 3306 端口。

-v -v $PWD/conf:/etc/mysql/conf.d：将主机当前目录下的 conf/my.cnf 挂载到容器的 /etc/mysql/my.cnf。

-v $PWD/logs:/logs：将主机当前目录下的 logs 目录挂载到容器的 /logs。

-v $PWD/data:/var/lib/mysql ：将主机当前目录下的data目录挂载到容器的 /var/lib/mysql 。

-e MYSQL_ROOT_PASSWORD=123456：初始化 root 用户的密码。
```

### 备注
#### 启动docker 启动mysql报错

```shell
docker run -p 3306:3306 --name mymysql -v $PWD/conf:/etc/mysql/conf.d -v $PWD/logs:/logs -v $PWD/data:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=123456 -d mysql:5.6
docker: Error response from daemon: Conflict. The container name "/mymysql" is already in use by container "7b2b60e00fc531a0eeb2dabb6d1a8105128c33effe07242f4be755e9411bb495". You have to remove (or rename) that container to be able to reuse that name.
```

#### 解决
```shell
docker ps -a
7b2b60e00fc5        mysql:5.6           "docker-entrypoint.s…"   3 months ago        Exited (255) 2 months ago   0.0.0.0:3306->3306/tcp     mymysql
```
看到之前运行docker容器还没有退出，导致出现容器重名情况
使用下面命令，删除容器
```shell
docker rm 7b2b60e00fc5
```
再次启动mysql发现解决


### 总结
用docker安装mysql容易方便很多,并且更容易管理,要删除mysql可直接用docker删除容器到方法,不用像本机安装一样,卸载到时候还要删除各种注册表和删除服务器才能卸载干净
---
title: docker安装mongo
date: 2019/01/17 17:00:00
categories: 技术
toc: True
tags: [docker,数据库]
---


### 前言
docker安装mongo

### 安装
```shell
docker pull mongo
#启动mongo
docker run -p 27017:27017 -v $PWD/db:/data/db -d mongo
```
做完上面两步发现就可以连接到mongo了

### 新增root用户
启动mongo后执行下面的命令
```shell
docker ps #查看mongo的容器id
docker exec -it  a7e5d4e4ca69  mongo admin #用admin 用户身份进入mongo
db.createUser({ user: 'root', pwd: '123456', roles: [ { role: "userAdminAnyDatabase", db: "admin" } ] }); #创建root用户
```

### 命令说明
```shell
-p 27017:27017 :将容器的27017 端口映射到主机的27017 端口

-v $PWD/db:/data/db :将主机中当前目录下的db挂载到容器的/data/db，作为mongo数据存储目录
```



### 总结
查看用户:db.system.users.find().pretty()
用docker安装mongo容易方便很多,并且更容易管理,要删除mongo可直接用docker删除容器的方法,不用像本机安装一样,卸载到时候还要删除各种注册表和删除服务器才能卸载干净
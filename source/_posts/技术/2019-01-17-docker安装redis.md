---
title: docker安装redis
date: 2019/01/17 11:00:00
categories: 技术
toc: True
tags: [js]
---
 

### 前言
docker安装redis

### 安装
```shell
#这里选择3.2版本,你可以安装其他到版本
docker pull  redis:3.2
#启动redis 并且映射本机端口和设置mysql密码
docker run -p 6379:6379 -v $PWD/data:/data  -d redis:3.2 redis-server --appendonly yes
```
做完上面两步发现就可以连接到redis了

### 命令说明
```shell
-p 6379:6379:将容器的6379端口映射到主机的6379端口
-v $PWD/data:/data:将主机中当前目录下的data挂载到容器的/data
redis-server --appendonly yes:在容器执行redis-server启动命令，并打开redis持久化配置
```

### 连接、查看容器
```shell
runoob@runoob:~/redis$ docker exec -it 43f7a65ec7f8 redis-cli
172.17.0.1:6379> info
# Server
redis_version:3.2.0
redis_git_sha1:00000000
redis_git_dirty:0
redis_build_id:f449541256e7d446
redis_mode:standalone
os:Linux 4.2.0-16-generic x86_64
arch_bits:64
multiplexing_api:epoll
```


### 总结
用docker安装redis容易方便很多,并且更容易管理
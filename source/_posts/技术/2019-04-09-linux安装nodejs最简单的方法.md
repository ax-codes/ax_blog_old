---
title: linux安装nodejs最简单的方法
date: 2019/04/09 11:00:00
categories: 技术
toc: True
tags: [js,linux]
---


### 前言
nodejs下载地址:
英文网址:https://nodejs.org/en/download/
中文网址:http://nodejs.cn/download/

### 安装
#### 下载
http://nodejs.cn/download/
![1.png](1.png)

#### 解压
tar -xvf   node-v6.10.0-linux-x64.tar.xz   
mv node-v6.10.0-linux-x64  nodejs 

#### 创建全局软连接
ln -s /app/software/nodejs/bin/npm /usr/local/bin/npm
ln -s /app/software/nodejs/bin/node /usr/local/bin/node
ln -s /root/nodejs/bin/pm2 /usr/local/bin/pm2

#### 测试
```shell
node -v
```
如果显示对应的版本,则说明成功
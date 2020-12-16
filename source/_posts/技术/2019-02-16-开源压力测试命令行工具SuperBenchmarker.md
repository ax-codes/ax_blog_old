---
title: 开源压力测试命令行工具SuperBenchmarker
date: 2019/02/16 11:00:00
categories: 技术
toc: True
tags: [.net/.net core,开发工具/插件,效率工具/插件,其他工具/插件]
---


### 前言
SuperBenchmarker 是ㄧ个开源的类似于Apache ab的压力测试命令行工具.可以在 .NET 4.52+ 或者 .NET Core 2.0+ 平台上运行.
可支持Get、Post、Put、Delete这些调用方式,调用时能指定Concurrent user、Request数、Header template…等.
可以从Github、Chocolatey这两种方式获得.
Github用户可在download目录内取得编译好的程序主文件
![1.jpg](1.jpg)

### 相关链接
免费网站与REST服务压力测试工具:http://blog.kkbruce.net/2013/09/free-website-rest-service-stress-test-tool.html?m=1
github:https://github.com/aliostad/SuperBenchmarker

### 安装
#### Installation - Windows
Easiest way to install sb is to use chocolatey. Once you have installed chocolatey, simply run:

> cinst SuperBenchmarker
and to update your version of sb:

> cup SuperBenchmarker
You can also download the lastest version from the Download folder of this github repository. This is a single exe with all dependencies IL-merged.

#### Installation - Mac

Currently, until brew is sorted out, you need to build from the source:

>git clone https://github.com/aliostad/SuperBenchmarker
cd SuperBenchmarker
./build.sh

### 参数
![2.png](2.png)
![3.png](3.png)

#### 一些比较重要的参数
-u 可用来指定要压测的网站或是API

-n 可用来指定要压的Request数量

-c 可用来指定Concurrent Request数量

-m 可用来指定要使用的HTTP Method

-h 可用来指定要显示HTTP Header

-q 可用来指定要显示Cookie

所以我们要发送1000个Request去测试腾讯网的话 可以输入命令

sb -u https://www.qq.com -n 1000

要发送1000个Request, 且同时间可能有10个Concurrent Request去测试腾讯网的话 可以输入命令

sb -u https://www.qq.com -n 1000 -c 10

要在发送命令后显示Header的话, 可带入参数-h

sb -u https://www.qq.com -n 1000 -c 10 -h

要在发送命令后显示Cookie, 可带入参数-q

sb -u https://www.qq.com -n 1000 -c 10 -h -q

### 运行
如果没有sb命令则在dotnet的环境下运行SuperBenchmarker.dll,并在末尾加上对应的参数:
例如:
```shell
dotnet ./src/SuperBenchmarker/bin/Debug/netcoreapp2.0/SuperBenchmarker.dll -u https://google.com -N 10
```

#### 效果
![4.png](4.png)
> 这边有简易的测试统计,可以看出每秒可处理多少的Request、最大的处理时间、最小的处理时间、平均的处理时间、以及压了这么多次的API,依比例分大概在哪个范围

![5.png](5.png)

> 这是网页来展现测试统计结果,每次跑完这个网页会自动在浏览器里弹出

这些数值有助我们评估网站或是API的性能与负载量. 除了看这些数据外,这边建议也可以在压的时候看一下Server上的CPU Loading,磁盘IO,以及内存的使用状况,甚至可以用性能监视器拉些数值来看.
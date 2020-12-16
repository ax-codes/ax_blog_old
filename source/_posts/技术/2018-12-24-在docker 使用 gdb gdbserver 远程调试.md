---
title: 在docker 使用 gdb(gnu) gdbserver(gnu)远程调试
date: 2018/12/24 20:00:00
categories: 技术
toc: True
tags: [docker,c语言,c++,开发工具/插件]
---

### 前言
<font style='color:red'>注意:</font> :这里说的gdb 和 gdbserver的版本都都是gnu的
gun gdb 官网地址:http://www.gnu.org/software/gdb/
gun gdb 官网文档地址:https://sourceware.org/gdb/current/onlinedocs/gdb/
gnu gdb下载地址:https://ftp.gnu.org/gnu/gdb/
在docker 使用 gdb gdbserver远程调试,在其他机器远程调试步骤应该是一样的

### 安装gdb 和 gdbserver 
#### 源码安装编译
编译 安装 gdb
1:在上面的连接下载对应版本的源码
2:进入源码根目录
3:./configure --with-all-targets (如果要跨平台编译的时候需要带上这个,不然跨平台调试gdb会报不可识别的文件格式问题)
4:make(这里编译需要比较长一段时间)
5:make install

编译 安装 gdbserver
1:进入src/gdbsever目录
2:./configure --with-all-targets (如果要跨平台编译的时候需要带上这个,不然跨平台调试gdb会报不可识别的文件格式问题)
3:make
4:make install

卸载 gdb
1:进入源码根目录的gdb文件夹
2:make uninstall 注意:在根目录uninstall不行

卸载 gdbserver
1:进入源码根目录的src的gdbserver文件夹
2:make uninstall

#### 源安装
mac 
```shell
brew install gdb --with-all-targets 
brew install gdb-gdbserver
```
centos 
```shell
yum install gdb
yum install gdb-gdbserver
```

### 开始调试
1:启动docker 容器,这里的2333 和 60522是宿主机器的端口,然后为了方便干脆把ssh的端口也开放,和映射clion测试项目的文件夹
```shell
docker run -ti  --security-opt seccomp=unconfined -p 127.0.0.1:2333:2333 -p 127.0.0.1:60522:22 -v /Users/ax/CLionProjects/untitled:/untitled centos:6 /bin/bash
```
2:容器里编译程序  
```shell
g++ main.cpp -o main
```
3:启动gdbserver 这里的main是需要调试的程序名, localhost:2333 表示占用本机的2333端口,在本机的情况下ip或者域名可以忽略
```shell
gdbserver localhost:2333 /untitled/main
```
4:开始调试 这里的localhsot:2333表示gdbserver在本机的2333端口,因为我启动容器的时候已经映射了端口; gdb target 有其他参数可以参考官网文档
在gdb的命令行下运行
```shell
target remote localhost:2333 
run
```

### clion 配置远程调试
1:Run -> Edit Configurations 中添加 GDB Remote Debug
2:在 Path mappings:remote 和 local都配置到对应的项目根目录(或者源码根目录)

### 注意
1:macos 默认是安装苹果的gdb版本,最好都安装gnu的gdb,如果需要远程调试最好用8.0.1的版本,因为8.1和8.2好像有bug;
2:mac 安装gdb一定要带上 "--with-all-targets" 并且一定要带上,不然远程调试linux程序的时候会报下面的错误
```shell
BFD: /Users/ax/CLionProjects/untitled3/cmake-build-debug/untitled3: unknown load command 0x32
BFD: /Users/ax/CLionProjects/untitled3/cmake-build-debug/untitled3: unknown load command 0x32
"/Users/ax/CLionProjects/untitled3/cmake-build-debug/./untitled3": not in executable format: 不可识别的文件格式
```
3:在docker 里远程gdb的时候docker run需要带上"--security-opt seccomp=unconfined"选项,不然在容器启动gdbserver(gdbserver 0.0.0.0:2333 /main) 的时候什么log都没输出,正常来说应该要显示启动gdbserver 调试和正在监听的端口log,所以别的机器gdb run的时候会报错
--security-opt seccomp=unconfined选项作用:Docker有个Seccomp filtering功能，以伯克莱封包过滤器（Berkeley Packet Filter，缩写BPF）的方式允许用户对容器内的系统调用（syscall）做自定义的“allow”, “deny”, “trap”, “kill”, or “trace”操作，由于Seccomp filtering的限制，在默认的配置下，会导致我们在用GDB的时候run失败，所以在执行docker run的时候加入–security-opt seccomp=unconfined这个参数，可以关闭seccomp profile的功能;官方解释:https://blog.docker.com/2016/02/docker-engine-1-10-security/
4:gdbserver 是本机的话,ip 和 域名可以忽略
5:clion 配置远程调试的时候 Path mappings:remote 和 local都配置到对应的项目根目录(或者源码根目录)

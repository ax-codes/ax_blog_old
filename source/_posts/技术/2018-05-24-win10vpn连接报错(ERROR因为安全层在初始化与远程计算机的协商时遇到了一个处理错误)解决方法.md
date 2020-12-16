---
title: win10vpn连接报错(ERROR因为安全层在初始化与远程计算机的协商时遇到了一个处理错误)解决方法
date: 2018/05/24 08:00:00
categories: 技术
toc: True
tags: 开发工具/插件
---

### Step 1.确保IPsec Policy Agent服务已启动

### Step 2.确保路由和远程访问（Routing and Remote Access）和远程访问连接管理器服务（Remote Access Connection Manager）启动

### Step 3.注册表添加 ProhibitIpSec 注册表项
```
注册表路径HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\Rasman\Parameters
创建ProhibitIpSec注册表项，选择DWORD类型并将其设置为 1 的值
```

### Step 4.注册表添加 AllowL2TPWeakCrypto 注册表项 
```
注册表路径HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\Rasman\Parameters
创建 AllowL2TPWeakCrypto 注册表项，选择DWORD类型并将其设置为 1 的值
```

### Step 5.重启计算机
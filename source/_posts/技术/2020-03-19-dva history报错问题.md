---
title: dva history报错问题
date: 2020/03/19 20:00:00
categories: 技术
toc: True
tags: [js]
---

### 前言

dva 版本:2.4.1

在项目配置好 dva 后,启动看到浏览器控制台报下面错误

### waring log

```
index.js:1 Warning: Please use `require("history").createHashHistory` instead of `require("history/createHashHistory")`. Support for the latter will be removed in the next major release.
```

### 解决

修改 dva 包的 lib 里的 index.js 里的 require("history/createHashHistory") 修改成 require("history").createHashHistory;如下图
![1.jpg](1.jpg)

暂时只能这样解决

#### 重启

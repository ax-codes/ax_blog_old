---
title: vscode运行code-runner的时候中文乱码
date: 2015/04/11 08:00:00
categories: 技术
toc: True
tags: [python,开发工具/插件,c++,csharp,.net/.net core]
---
### 问题
vscode运行code-runner的时候中文乱码,但在终端显示不会

### 解决
在setting里加入
```json
"code-runner.runInTerminal": true,
```
表示将我们的将内容输出到终端显示
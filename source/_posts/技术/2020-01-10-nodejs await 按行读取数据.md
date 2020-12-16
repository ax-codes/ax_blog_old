---
title: nodejs await 按行读取数据
date: 2019/01/10 20:00:00
categories: 技术
toc: True
tags: [js]
---

### 前言

nodejs await 按行读取数据

### 代码

```js
const fs = require('fs');
const readline = require('readline');

var lineNumber = 1;

async function processLineByLine() {
  const fileStream = fs.createReadStream('./file.txt');

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity
  });
  // 注意：我们使用crlfDelay选项来识别CR LF的所有实例
  // （'\ r \ n'）作为单个换行符在input.txt中。

  for await (const line of rl) {
    //input.txt中的每一行都将在此处作为“ line”连续可用。
    console.log(`${lineNumber++}: ${line}`);
  }
}

processLineByLine();
```

### 使用

#### 文件头部注释：

在当前编辑文件中使用快捷键:window：ctrl+alt+i/mac：ctrl+cmd+i,即可生成文件头部注释。

#### 函数注释：

将光标放在函数行或者将光标放在函数上方的空白行
使用快捷键 window：ctrl+alt+t,mac：ctrl+cmd+t，即可生成函数注释。
事实上，函数注释在文件的任意位置都可生成，这里需要自己控制。

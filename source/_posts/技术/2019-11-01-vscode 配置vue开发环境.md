---
title: vscode 配置vue开发环境
date: 2019/11/01 17:00:00
categories: 技术
toc: True
tags: [js, 开发工具/插件, 效率工具/插件]
---

### 前言

vscode 配置 vue 开发环境

### 安装 vscode

下载地址:https://code.visualstudio.com/

### 安装 color 主题

在 vscode 扩展程序里搜索 One Dark Pro 然后进行安装

### 安装 icon 主题

在 vscode 扩展程序里搜索 Material Icon Theme 然后进行安装

### 安装 vue(高亮 vue 代码)

在 vscode 扩展程序里搜索 vue 然后进行安装

### 安装 Prettier

```
ext install esbenp.prettier-vscode
```

### 安装 Eslint

在 vscode 扩展程序里搜索 Eslint 然后进行安装

### 修改 setting.json

```
{
  "editor.tabSize": 2,
  "editor.detectIndentation": false,
  "editor.formatOnType": false,
  "editor.formatOnPaste": true,
  "editor.formatOnSave": true,
  "prettier.tabWidth": 2,
  "prettier.semi": true,
  "prettier.singleQuote": true,
  "[javascript]": {
    "editor.defaultFormatter": "esbenp.prettier-vscode"
  },
  "[html]": {
    "editor.defaultFormatter": "esbenp.prettier-vscode"
  },
  "[markdown]": {
    "editor.defaultFormatter": "esbenp.prettier-vscode"
  },
  "vetur.format.options.tabSize": 2,
  "vetur.format.defaultFormatter.html": "prettyhtml",
  "vetur.format.defaultFormatter.js": "vscode-typescript",
  "javascript.format.insertSpaceBeforeFunctionParenthesis": true,
  "eslint.autoFixOnSave": true,
  "eslint.validate": [
    "javascript",
    "html",
    {
      "language": "vue",
      "autoFix": true
    }
  ],
  "workbench.iconTheme": "material-icon-theme",
  "workbench.colorTheme": "One Dark Pro"
}
```

### 配置.prettierrc.js

在项目根目录新增.prettierrc.js 文件新增内容

```
module.exports = {
  printWidth: 200, // 最大打印宽度,超出将换行
  singleQuote: false, // 默认单引号 ,false 默认使用双引号
  bracketSpacing: true,
  jsxBracketSameLine: true,
  htmlWhitespaceSensitivity: "ignore" // 问题1中的设置
};

```

### 配置.eslintrc.js

在项目根目录新增.eslintrc.js 文件新增内容

原因:
修改了 Prettier 格式化后 ESlint 检查警报,并更改了我的代码格式.
首先检查 ESlint 配置是否使用了 prettier 规则,如果确定使用了,则是一些自定义规则在 ESlint 和 Prettier 插件中的配置不一致导致的。检查 eslintrc.js

```
module.exports = {
  root: true,
  env: {
    node: true
  },
  extends: ['plugin:vue/essential', '@vue/standard'],
  rules: {
    'no-console': process.env.NODE_ENV === 'production' ? 'error' : 'off',
    'no-debugger': process.env.NODE_ENV === 'production' ? 'error' : 'off'
  },
  parserOptions: {
    parser: 'babel-eslint'
  }
}

```

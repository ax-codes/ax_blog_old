---
title: react a标签eslint问题
date: 2020/03/18 20:00:00
categories: 技术
toc: True
tags: [js]
---

### 前言

react a 标签 eslint 问题

### waring log

```
  Line 10:33:  The href attribute requires a valid value to be accessible. Provide a valid, navigable address as the href value. If you cannot provide a valid href, but still need the element to resemble a
link, use a button and change it with appropriate styles. Learn more: https://github.com/evcohen/eslint-plugin-jsx-a11y/blob/master/docs/rules/anchor-is-valid.md         jsx-a11y/anchor-is-valid
```

### 解决

#### 在 eslint 的配置加上的 rules 加上

```
"jsx-a11y/anchor-is-valid": "off"
```

例如我的 create-react-app 项目的.eslintrc.json 的配置是:

```json
{
  "extends": "react-app",
  "rules": {
    "jsx-a11y/anchor-is-valid": "off"
  }
}
```

#### a 标签改成

```html
<a href="# ">{text}</a>
```

> 注意:#后面有一个空格

#### 重启

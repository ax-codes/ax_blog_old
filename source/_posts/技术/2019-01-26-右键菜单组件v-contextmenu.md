---
title: 右键菜单组件v-contextmenu
date: 2019/01/26 11:00:00
categories: 技术
toc: True
tags: [web前端,js]
---


### 前言
右键菜单组件:v-contextmenu
github地址:https://github.com/snokier/v-contextmenu
文档说明:https://github.com/snokier/v-contextmenu/blob/master/docs/usage.md#vcontextmenu
在线例子:https://snokier.github.io/v-contextmenu/
例子代码:https://github.com/snokier/v-contextmenu/tree/master/examples
在线事例:https://github.com/snokier/v-contextmenu/blob/master/docs/images/example.gif

### cdn引入 
```shell
<!-- 引入 Vue -->
<script src="https://unpkg.com/vue/dist/vue.js"></script>

<!-- 引入 VContextmenu 组件 -->
<script src="https://unpkg.com/v-contextmenu/dist/index.js"></script>

<!-- 引入 VContextmenu 组件样式 -->
<link rel="stylesheet" href="https://unpkg.com/v-contextmenu/dist/index.css">


```

### npm安装
```shell
$ npm i -S v-contextmenu # yarn add v-contextmenu
```

### 概览
![1.png](1.png)

### 测试模版    
```html
<!DOCTYPE html>
<html>

<head>
  <meta charset="UTF-8">
  <!-- import CSS -->
  <link rel="stylesheet" href="https://unpkg.com/element-ui/lib/theme-chalk/index.css">
  <!-- 引入 VContextmenu 组件样式 -->
  <link rel="stylesheet" href="https://unpkg.com/v-contextmenu/dist/index.css">
</head>

<body>
  <div id="app">
    <template>
      <v-contextmenu ref="contextmenu">
        <v-contextmenu-item @click="handleClick">菜单1</v-contextmenu-item>
        <v-contextmenu-item @click="handleClick">菜单2</v-contextmenu-item>
        <v-contextmenu-item @click="handleClick">菜单3</v-contextmenu-item>
      </v-contextmenu>

      <div  v-contextmenu:contextmenu>右键点击此区域</div>
    </template>
  </div>
</body>

<!-- import Vue before Element -->
<script src="https://unpkg.com/vue/dist/vue.js"></script>
<!-- import JavaScript -->
<script src="https://unpkg.com/element-ui/lib/index.js"></script>
<!-- 引入 VContextmenu 组件 -->
<script src="https://unpkg.com/v-contextmenu/dist/index.js"></script>


<script>
  new Vue({
    el: '#app',
    methods: {
      handleClick(vm, event) {
        alert(`「${vm.$slots.default[0].text}」被点击啦！`)
      }
    }
  })
</script>

</html>
```
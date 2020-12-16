---
title: Vue学习篇(六)-Vue设置dom样式
date: 2019/01/21 10:00:00
categories: 技术
toc: True
tags: [web前端,js]
---


### 前言
Vue里设置dom的样式,我们需要使用到v-bind:class这个指令来设置样式,v-bind:class我们不仅可以使用对象还能使用数组,或者直接v-bind:style设置样式


### v-bind:class 对象设置样式
```js
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title></title>
<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>
<style>
.active {
	width: 100px;
	height: 100px;
	background: green;
}
.text-danger {
	background: red;
}
</style>
</head>
<body>
<div id="app">
  <div class="static"
     v-bind:class="{ active: isActive, 'text-danger': hasError }">
  </div>
</div>

<script>
new Vue({
  el: '#app',
  data: {
    isActive: true,
	hasError: true
  }
})
</script>
</body>
</html>
```
>解释：当isActive为true时使用.active,当hasError为true时使用.text-danger,反之则不使用,所以该dom的class='static active text-danger',会包含默认的,且后面的样式会覆盖前面的样式

### v-bind:class 数组设置样式
```js
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title></title>
<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>
<style>
.active {
	width: 100px;
	height: 100px;
	background: green;
}
.text-danger {
	background: red;
}
</style>
</head>
<body>
<div id="app">
	<div v-bind:class="[activeClass, errorClass]"></div>
</div>

<script>
new Vue({
  el: '#app',
  data: {
    activeClass: 'active',
    errorClass: 'text-danger'
  }
})
</script>
</body>
</html>
```
>解释：该dom最后的class为'active text-danger'

### v-bind:class 三元运算符设置样式
```js
<div v-bind:class="[errorClass ,isActive ? activeClass : '']"></div>
```

### v-bind:style 直接设置样式
1.直接使用字段属性设置样式
```js
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title></title>
<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>
</head>
<body>
<div id="app">
	<div v-bind:style="{ color: activeColor, fontSize: fontSize + 'px' }">测试</div>
</div>

<script>
new Vue({
  el: '#app',
  data: {
    activeColor: 'green',
	fontSize: 30
  }
})
</script>
</body>
</html>
```
>解释:使用v-bind:style可以直接设置css属性

2.绑定样式对象设置样式
```js
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title></title>
<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>
</head>
<body>
<div id="app">
  <div v-bind:style="styleObject">测试</div>
</div>

<script>
new Vue({
  el: '#app',
  data: {
    styleObject: {
      color: 'green',
      fontSize: '30px'
    }
  }
})
</script>
</body>
</html>
```

3.使用数组设置绑定对象样式
```js
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title></title>
<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>
</head>
<body>
<div id="app">
  <div v-bind:style="[baseStyles, overridingStyles]"></div>
</div>

<script>
new Vue({
  el: '#app',
  data: {
    baseStyles: {
      
		: 'green',
      fontSize: '30px'
    },
	overridingStyles: {
      'font-weight': 'bold'
    }
  }
})
</script>
</body>
</html>
```

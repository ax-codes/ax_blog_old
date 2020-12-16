---
title: Element tree组件右键菜单demo
date: 2019/01/28 11:00:00
categories: 技术
toc: True
tags: [web前端,js]
---


### 前言
Element tree组件右键增删查改

### 引用样式
```html
<!-- import CSS -->
<link rel="stylesheet" href="https://unpkg.com/element-ui/lib/theme-chalk/index.css">
<!-- 引入 VContextmenu 组件样式 -->
<link rel="stylesheet" href="https://unpkg.com/v-contextmenu/dist/index.css">
```

### 引用js
```html
<!-- import Vue before Element -->
<script src="https://unpkg.com/vue/dist/vue.js"></script>
<!-- import JavaScript -->
<script src="https://unpkg.com/element-ui/lib/index.js"></script>
<!-- 引入 VContextmenu 组件 -->
<script src="https://unpkg.com/v-contextmenu/dist/index.js"></script>
```

### 代码
```html
<!DOCTYPE html>
<html class="box">

<head>
  <meta charset="UTF-8">
  <!-- import CSS -->
  <link rel="stylesheet" href="https://unpkg.com/element-ui/lib/theme-chalk/index.css">
  <!-- 引入 VContextmenu 组件样式 -->
  <link rel="stylesheet" href="https://unpkg.com/v-contextmenu/dist/index.css">
</head>

<body class="box">
  <div id="app">
    <el-container style="width:500px">
      <el-header>
        <el-input placeholder="输入关键字进行过滤" v-model="filterText">
        </el-input>
      </el-header>
      <el-main>
        <el-tree class="filter-tree" :data="data2" :props="defaultProps" @node-click="treeNodeClick" default-expand-all
          :filter-node-method="filterNode" ref="tree2">
          <span class="custom-tree-node" slot-scope="{ node, data }">
            <span class="el-tree-node__label" v-contextmenu:contextmenu>{{ node.label }}</span>
          </span>
        </el-tree>


        <template>
          <v-contextmenu ref="contextmenu">
            <v-contextmenu-item @click="handleClick">新增节点</v-contextmenu-item>
            <v-contextmenu-item @click="handleClick">修改节点</v-contextmenu-item>
            <v-contextmenu-item @click="handleClick">删除节点</v-contextmenu-item>
          </v-contextmenu>
        </template>
      </el-main>
    </el-container>
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
    data() {
      return {
        filterText: '',
        data2: [{
          id: 1,
          label: '一级 1',
          children: [{
            id: 4,
            label: '二级 1-1',
            children: [{
              id: 9,
              label: '三级 1-1-1'
            }, {
              id: 10,
              label: '三级 1-1-2'
            }]
          }]
        }, {
          id: 2,
          label: '一级 2',
          children: [{
            id: 5,
            label: '二级 2-1'
          }, {
            id: 6,
            label: '二级 2-2'
          }]
        }, {
          id: 3,
          label: '一级 3',
          children: [{
            id: 7,
            label: '二级 3-1'
          }, {
            id: 8,
            label: '二级 3-2'
          }]
        }],
        defaultProps: {
          children: 'children',
          label: 'label'
        }
      };
    },
    watch: {
      filterText(val) {
        this.$refs.tree2.filter(val);
      }
    },
    props: {
      theme: String,
    },
    methods: {
      treeNodeClick() {
        this.$refs.contextmenu.hide();
      },
      handleClick(vm, event) {
        alert(`「${vm.$slots.default[0].text}」被点击啦！`)
      },
      filterNode(value, data) {
        if (!value) return true;
        return data.label.indexOf(value) !== -1;
      }
    }
  })
</script>
<style scoped>
  .box {
    height: 100%;
  }
</style>

</html>
```

### 效果
![1.jpg](1.jpg)
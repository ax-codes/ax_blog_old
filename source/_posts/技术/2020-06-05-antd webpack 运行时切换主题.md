---
title: antd webpack 运行时切换主题
date: 2020/06/05 20:00:00
categories: 技术
toc: True
tags: [js, 开发工具/插件]
---

### 前言

antd 版本:^4.1.4(和高版本没关系,我升级到最新版本样式适配到还是不怎么好)
antd-theme-webpack-plugin:版本^1.3.4

antd 4.0 以后引入了黑夜主题,因为觉得加上主题切换会让系统显得高级一点,所以在此记录一下

### 安装插件

```
tyarn add antd-theme-webpack-plugin antd-theme-generator -D
```

备注:安装到开发环境就行

### webpack 配置

### 引入文件

![414d0722-3f9e-4bee-805e-4753daa47408](414d0722-3f9e-4bee-805e-4753daa47408.png)
这几个文件可以这里下载:https://github.com/mzohaibqc/antd-theme-webpack-plugin/tree/master/examples/customize-cra/src

#### 定义配置

```js
// eslint-disable-next-line @typescript-eslint/no-var-requires
const AntDesignThemePlugin = require("antd-theme-webpack-plugin");
// eslint-disable-next-line @typescript-eslint/no-var-requires
const { getLessVars } = require("antd-theme-generator");

const themeVariables = getLessVars(
  resolve(PROJECT_ROOT, "./src/assets/styles/vars.less")
);
const defaultVars = getLessVars(
  "./node_modules/antd/lib/style/themes/default.less"
);
const darkVars = {
  ...getLessVars("./node_modules/antd/lib/style/themes/dark.less"),
  "@primary-color": defaultVars["@primary-color"],
};
const lightVars = {
  ...getLessVars("./node_modules/antd/lib/style/themes/compact.less"),
  "@primary-color": defaultVars["@primary-color"],
};
fs.writeFileSync("./src/assets/dark.json", JSON.stringify(darkVars));
fs.writeFileSync("./src/assets/light.json", JSON.stringify(lightVars));
fs.writeFileSync("./src/assets/theme.json", JSON.stringify(themeVariables));

const options = {
  stylesDir: resolve(PROJECT_ROOT, "./src/assets/"),
  antDir: resolve(PROJECT_ROOT, "./node_modules/antd"),
  varFile: resolve(PROJECT_ROOT, "./src/assets/styles/vars.less"),
  themeVariables: [
    ...new Set([
      ...Object.keys(darkVars),
      ...Object.keys(lightVars),
      ...Object.keys(themeVariables),
    ]),
  ],
  generateOnce: false, // generate color.less on each compilation
};
```

#### webpack 安装插件

```js
new AntDesignThemePlugin(options); //引用上面定义到options
```

### less-loader 加载器关闭 javascript

```js
{
  javascriptEnabled: true;
}
```

eg:

```js
{
    test: /\.less$/,
    exclude: /node_modules/,
    use: [
        ...getCssLoaders(2, true),
        {
            loader: 'less-loader',
            options: {
                javascriptEnabled: true,
            },
        },
    ],
},
```

### index.html 添加脚本

在你的 html 主体文件 body 里开头添加下列代码(一般 webpack 主体文件都是 public 里的 index.html)

```html
<link rel="stylesheet/less" type="text/css" href="/color.less" />
<script>
  window.less = {
    async: false,
    env: "production",
  };
</script>
<script
  type="text/javascript"
  src="https://cdnjs.cloudflare.com/ajax/libs/less.js/2.7.2/less.min.js"
></script>
```

### 添加动态切换逻辑代码

#### 引入前面加入的对应 json 文件,比如黑色主题就是 dark.json

```js
import darkVars from "@/assets/dark.json";
```

#### 添加切换主题逻辑,使用上面引入的 json 文件进行主题切换

```js
window.less
  .modifyVars(darkVars)
  .then(() => {
    message.success("切换主题成功");
  })
  .catch(() => {
    message.error(`切换主题失败`);
  });
```

#### 最终效果

![6009a5fd-7e35-41f4-8f43-e317dcd826aa](6009a5fd-7e35-41f4-8f43-e317dcd826aa.png)

#### 备注

以后加样式的适合要注意各种主题都要测试,有些没有的样式可能需要自定义适配

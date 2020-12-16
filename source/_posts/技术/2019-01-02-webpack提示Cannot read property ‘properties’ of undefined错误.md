---
title: webpack提示Cannot read property ‘properties’ of undefined错误
date: 2019/01/02 11:00:00
categories: 技术
toc: True
tags: [web前端,js]
---


### 前言
nom install的时候报错提示Cannot read property ‘properties’ of undefined错误

### 报错log
```shell
> v-contextmenu@2.8.0 dev /Users/guoxing/test/v-contextmenu
> cross-env NODE_ENV=development webpack-dev-server --progress --config examples/webpack.config.js

/Users/guoxing/test/v-contextmenu/node_modules/webpack-cli/bin/config-yargs.js:89
                                describe: optionsSchema.definitions.output.properties.path.description,
                                                                           ^

TypeError: Cannot read property 'properties' of undefined
    at module.exports (/Users/guoxing/test/v-contextmenu/node_modules/webpack-cli/bin/config-yargs.js:89:48)
    at Object.<anonymous> (/Users/guoxing/test/v-contextmenu/node_modules/webpack-dev-server/bin/webpack-dev-server.js:84:40)
    at Module._compile (internal/modules/cjs/loader.js:689:30)
    at Object.Module._extensions..js (internal/modules/cjs/loader.js:700:10)
    at Module.load (internal/modules/cjs/loader.js:599:32)
    at tryModuleLoad (internal/modules/cjs/loader.js:538:12)
    at Function.Module._load (internal/modules/cjs/loader.js:530:3)
    at Function.Module.runMain (internal/modules/cjs/loader.js:742:12)
    at startup (internal/bootstrap/node.js:283:19)
    at bootstrapNodeJSCore (internal/bootstrap/node.js:743:3)
npm ERR! code ELIFECYCLE
npm ERR! errno 1
npm ERR! v-contextmenu@2.8.0 dev: `cross-env NODE_ENV=development webpack-dev-server --progress --config examples/webpack.config.js`
npm ERR! Exit status 1
npm ERR!
npm ERR! Failed at the v-contextmenu@2.8.0 dev script.
npm ERR! This is probably not a problem with npm. There is likely additional logging output above.

npm ERR! A complete log of this run can be found in:
npm ERR!     /Users/guoxing/.npm/_logs/2019-01-26T06_44_11_498Z-debug.log
```

### 解决
出现这个错误是因为webpack-cli版本的问题，升级到3.1.1版本或更新即可
```shell
npm i webpack-cli@3.1.1 -D
```
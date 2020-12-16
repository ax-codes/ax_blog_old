---
title: nodejs 的orm框架sequelize
date: 2019/05/20 17:00:00
categories: 技术
toc: True
tags: [js]
---


### 前言
github:https://github.com/sequelize
中文api:https://github.com/demopark/sequelize-docs-Zh-CN
express-example:https://github.com/sequelize/express-example
sequelize-cli:https://github.com/sequelize/cli
sequelize-auto github:https://github.com/sequelize/sequelize-auto

### 安装
#### 安装sequelize库
```shell
$ npm install --save sequelize # This will install v5

# And one of the following:
$ npm install --save pg pg-hstore # Postgres
$ npm install --save mysql2
$ npm install --save mariadb
$ npm install --save sqlite3
$ npm install --save tedious # Microsoft SQL Server
```

#### 安装sequelize脚手架
Globally 安装
```
Install CLI globally with

$ npm install -g sequelize-cli
Now you can run CLI using following command anywhere

$ sequelize
```

Locally
```
Install CLI locally to your node_modules folder with

$ npm install --save sequelize-cli
You should be able to run CLI with

$ node_modules/.bin/sequelize
```

```shell
命令：
  db：migrate运行挂起的迁移
  db：migrate：schema：timestamps：添加更新迁移表以具有时间戳
  db：migrate：status列出所有迁移的状态
  db：migrate：undo恢复迁移
  db：migrate：undo：all恢复所有迁移
  db：seed运行指定的播种器
  db：seed：undo删除数据库中的数据
  db：seed：all运行每个播种机
  db：seed：undo：all从数据库中删除数据
  db：create创建由配置指定的数据库
  db：drop由配置指定的Drop数据库
  init初始化项目
  init：config初始化配置
  init：迁移初始化迁移
  init：models初始化模型
  init：播种机初始化播种机
  migration：generate生成新的迁移文件[aliases：migration：create]
  model：generate生成模型及其迁移[aliases：model：create]
  seed：generate生成一个新的种子文件[别名：seed：create]

选项：
  --version显示版本号[boolean]
  --help显示帮助[boolean]
```

#### 安装sequelize-auto
```shell
npm install -g sequelize-auto
```

在使用sequelize-auto之前,您需要全局安装正确数据库组件
```
Example for MySQL/MariaDB

npm install -g mysql

Example for Postgres

npm install -g pg pg-hstore

Example for Sqlite3

npm install -g sqlite

Example for MSSQL

npm install -g mssql
```

```
[node] sequelize-auto -h <host> -d <database> -u <user> -x [password] -p [port] --dialect [dialect] -c [/ path / to / config] -o [ / path / to / models] -t [tableName] -C

选项：
  -h， - 数据库的主机IP /主机名。 [需要]
  -d， - 数据库数据库名称。 [需要]
  -u， -  user数据库的用户名。
  -x， -  pass数据库的密码。
  -p， -  port数据库的端口号。
  -c， -  config Sequelize的构造函数“options”标志对象的JSON文件，如下所示：https：//sequelize.readthedocs.org/en/latest/api/sequelize/
  -o， -  output用于放置模型的目录。
  -e， -  dialect你正在使用的方言/引擎：postgres，mysql，sqlite
  -a， - 附加到包含模型定义（适用于所有表）的json文件的路径，这些模型定义将在模型的配置参数中定义。有关更多信息：https：//sequelize.readthedocs.org/en/latest/docs/models-definition/#configuration
  -t， -  tables要导入的表的逗号分隔名称
  -T， -  skip-tables要跳过的以逗号分隔的表名
  -C，--camel使用驼峰案例命名模型和字段
  -n， -  no-write防止将模型写入磁盘。
  -s，--schema用于检索表的数据库模式
  -z， -  anpescript输出模型作为带有定义文件的打字稿。
```

mysql 根据db 生成models例子
```shell
sequelize-auto -h localhost -d node_test -u root -x 123456 -p 3306 -o /Users/guoxing/test/express-example-sequelize/express-example/db/models
```

程序api
```shell
var SequelizeAuto = require('sequelize-auto')

var auto = new SequelizeAuto('database', 'user', 'pass', {
    host: 'localhost',
    dialect: 'mysql'|'mariadb'|'sqlite'|'postgres'|'mssql',//默认选择一个就行
    directory: false, // prevents the program from writing to disk//是否生成文件
    port: 'port',
    output:'./models',//生成的model 路径
    additional: {
        timestamps: false
        //...
    },
    tables: ['table1', 'table2', 'table3'] //注释表示生成全部表
    //...
})


auto.run(function (err) {
  if (err) throw err;

  console.log(auto.tables); // table list
  console.log(auto.foreignKeys); // foreign key list
});
```


### 在项目里加入sequelize
#### 在项目根目录里
```shell
touch .sequelizerc
```
#### 修改.sequelizerc
```
const path = require('path');

module.exports = {
  'config': path.resolve('config', 'db.js'),
  'models-path': path.resolve('db', 'models'),
  'seeders-path': path.resolve('db', 'seeders'),
  'migrations-path': path.resolve('db', 'migrations')
}
```
#### 初始化sequelize项目,会根据.sequelizerc的路径生成项目结构
```shell
sequelize init
```

#### 修改db/db.js
```shell
module.exports = {
  development: {
    username: 'root',
    password: 'root',
    database: 'test_gx',
    host: '127.0.0.1',
    dialect: 'mysql'
  },
  test: {
    dialect: "sqlite",
    storage: ":memory:"
  },
  production: {
    username: 'root',
    password: '123456',
    database: 'node_test',
    host: '127.0.0.1',
    dialect: 'mysql'
    // use_env_variable: 'DATABASE_URL'
  }
};
```

#### 创建自己的一些工具
```shell
cd db
mkdir tools
touch dbToModels.js
touch modelsToDb.js
```

#### dbToModels.js内容
```
var config = require('../../config/db');
var SequelizeAuto = require('sequelize-auto')

var auto = new SequelizeAuto(config.development.database,config.development.username,config.development.password, {
    host: config.development.host,
    c: 'mysql',
    port: '3306',
    directory: '../models',
    additional: {
        timestamps: false
        //...
    }
    //...
})

auto.run(function (err) {
    if (err) throw err;
  
    console.log(auto.tables); // table list
    console.log(auto.foreignKeys); // foreign key list
  });
  
```
#### modelsToDb.js内容
```
var db = require('../models/index');

//model 导入到 db
db.sequelize.sync({force:true});
```

#### 执行dbToModels.js生成models
```shell
node dbToModels.j
```

#### 下面就可以在你需要操作数据库的地方使用了
```js
var models = require('./db/models');

var list = models.user.findAll();
```


### 总结
sequelize是一种基于node的orm框架,可以映射对象和数据表的关系简化操作数据的方法,因为sequelize帮我们封装好了操作数据库的接口,所以当我们需要切换不同类型的数据库的时候我们业务层的逻辑也是不用修改的,只需要在配置上下文的时候配置其他的数据库就行,并且sequelize还提供了其他的功能,比如迁移和种子,和校验等功能,这里没有过多介绍,详情可以看sequelize 的github
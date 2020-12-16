---
title: nodejs 操作mysql demo
date: 2019/04/08 11:00:00
categories: 技术
toc: True
tags: [js]
---


### 前言
需要先安装mysql模块:npm install mysql -g

### 代码
#### 没有链接池
```js
var mysql = require('mysql');

var connection = mysql.createConnection({
host: '192.168.199.222',
user: 'root',
password: 'root',
database: 'db'
});

connection.connect();

connection.query('select * from test where propertyName=\'viewingAnalysisMonitor\'', function (error, results, fields) {
if (error) throw error;
//results:数据集
//results[0]:第一行数据
console.log(results[0].propertyValue);
});

connection.end();
```
#### 连接池
```js
var mysql = require('mysql');

const pool = mysql.createPool({
    host: '127.0.0.1',
    user: 'root',
    password: 'root',
    database: 'test'
});

module.exports.query = function (sql, values) {
    // 返回一个 Promise
    return new Promise((resolve, reject) => {
        pool.getConnection(function (err, connection) {
            if (err) {
                reject(err)
            } else {
                connection.query(sql, values, (err, rows) => {

                    if (err) {
                        reject(err)
                    } else {
                        resolve(rows)
                    }
                    // 结束会话
                    connection.release()
                })
            }
        })
    })
}

let result = await Ut.query('select * from test where propertyName=\'viewingAnalysisMonitor\'');
```






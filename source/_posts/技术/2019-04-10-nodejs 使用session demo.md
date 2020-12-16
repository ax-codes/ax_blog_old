---
title: nodejs 使用session demo
date: 2019/04/10 11:00:00
categories: 技术
toc: True
tags: [js]
---


### 前言
session是临时存储在服务器内存里的数据,常用于记录用户登陆标识,但是server重启的话,session数据回丢失,所以使用redis比较好一点

### demo
```js
var app=require('express')();
var request=require('request');
var querystring=require('querystring');
var crypto=require('crypto');
var bodyParser=require('body-parser');
var cookieParser=require('cookie-parser');
var session = require('express-session');
var FileStore = require('session-file-store')(session);

var identityKey = 'skey';
 
app.use(session({
  name: identityKey,
  secret: 'chyingp', // 用来对session id相关的cookie进行签名
  store: new FileStore(), // 本地存储session（文本文件，也可以选择其他store，比如redis的）
  saveUninitialized: false, // 是否自动保存未初始化的会话，建议false
  resave: false, // 是否每次都重新保存会话，建议false
  cookie: {
    maxAge: 10 * 1000 // 有效期，单位是毫秒
  }
}));

//使用JSON解析工具
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());
//使用cookie
app.use(cookieParser());
//开启监听
var server=app.listen(8889, function(){
    var host=server.address().address;
    var port=server.address().port;
    console.log('address is http://%s:%s', host, port);
});

app.get('/create_session', function(req, res, next){
    req.session.loginUser = req.query.name;
    res.json({ret_code: 0, ret_msg: req.query.name+'创建成功'}); 
});


app.get('/get_session', function(req, res, next){
    res.json({ret_code: 0, ret_msg: req.session.loginUser}); 
});

app.get('/clear_session', function(req, res, next){
    req.session.loginUser = null;
    res.json({ret_code: 0, ret_msg: '清除成功'}); 
});
```

### 测试
```
http://localhost:8889/create_session?name=axing
http://localhost:8889/get_session
http://localhost:8889/clear_session
```
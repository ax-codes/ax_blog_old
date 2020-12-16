---
title: express session存内存demo
date: 2020/05/24 20:00:00
categories: 技术
toc: True
tags: [js]
---

### 前言

express session 存内存 demo

### 代码

```js
var express = require("express");
var app = express();
var cookieParser = require("cookie-parser");
var session = require("express-session");

app.use(cookieParser());
app.use(
  session({
    secret: "12345",
    name: "name",
    cookie: { maxAge: 60000 },
    resave: false,
    saveUninitialized: true,
  })
);

app.get("/set_session", async function (req, res) {
  req.session.name = "ax";
  return res.json({ data: "设置session成功" });
});

app.get("/get_session", async function (req, res) {
  const name = req.session.name;
  return res.json({ data: `session value = ${name}` });
});

var server = app.listen(9001, function () {
  var host = server.address().address;
  var port = server.address().port;
  console.log("应用实例，访问地址为 http://%s:%s", host, port);
});
```

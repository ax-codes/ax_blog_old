---
title: node socket client 模板
date: 2019/09/23 17:00:00
categories: 技术
toc: True
tags: [js]
---


### 前言
node socket client 模板

### 代码
```js
// Requires
const net = require('net');

// Create socket
const port = 9011;
const host = '127.0.0.1';
const timeout = 1000;
let retrying = false;

// Functions to handle socket events
function makeConnection () {
    socket.connect(port, host);
}
function connectEventHandler() {
    console.log('connected');
    retrying = false;
}
function dataEventHandler() {
    console.log('data');
}
function endEventHandler() {
    console.log('end');
}
function timeoutEventHandler() {
    console.log('timeout');
}
function drainEventHandler() {
    console.log('drain');
}
function errorEventHandler() {
    console.log('error');
}
function closeEventHandler () {
    console.log('close');
    if (!retrying) {
        retrying = true;
        console.log('Reconnecting...');
    }
    setTimeout(makeConnection, timeout);
}

// Create socket and bind callbacks
let socket = new net.Socket();
socket.on('connect', connectEventHandler);
socket.on('data',    dataEventHandler);
socket.on('end',     endEventHandler);
socket.on('timeout', timeoutEventHandler);
socket.on('drain',   drainEventHandler);
socket.on('error',   errorEventHandler);
socket.on('close',   closeEventHandler);

// Connect
console.log('Connecting to ' + host + ':' + port + '...');
makeConnection();
```
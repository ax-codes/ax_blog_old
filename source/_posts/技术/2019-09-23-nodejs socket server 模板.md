---
title: nodejs socket server 模板
date: 2019/09/23 17:00:00
categories: 技术
toc: True
tags: [js]
---


### 前言
nodejs socket server 模板
心跳监测 数据监测和推送 登录

### 代码
```js
let net = require('net');
const log4js = require("./util/log4js");
const logger = log4js.getLogger("info");
var common = require('./common.js');
const querystring = require('querystring');
let moment = require('moment');
moment.locale('zh-cn');

let clients = [];

//登录
let reqLoginAlarmFail = 'ackLoginAlarm;result=fail;resDesc={_resDesc}';
let reqLoginAlarmSucc = 'ackLoginAlarm;result=succ;resDesc=null';
let loginStatus = false

//心跳
let headbeatPack = `ackHeartBeat;reqId={_reqId};time({_time})`
let headbeatPackInterval = 50000 //(/ms)
let headbeatTimeout = 180 //(/s)
let headbeatIntervalObj = null

//告警监测
let alertListenIntervalObj = null
let alertListenInterval = 30000 //(/ms)



//清除调度
function clearAllInterval() {
    logger.info("监测:心跳监测关闭");
    clearInterval(headbeatIntervalObj);
    logger.info("监测:监听告警数据关闭");
    clearInterval(alertListenIntervalObj);
}


//登录处理
function loginProcessFun(client, loginCount, data) {
    if (data.user == 'yiy' && data.key == 'qw#$@') {
        logger.info(`${client.remoteAddress}:${client.remotePort}登录成功`);
        common.writeData(client, reqLoginAlarmSucc);
        client.loginStatus = true;
        clients[`${client.remoteAddress}:${client.remotePort}`] = client;
        return 0;
    }

    logger.info(`${client.remoteAddress}:${client.remotePort}登录失败`);

    common.writeData(client, reqLoginAlarmFail.replace('{_resDesc}','username-error or password-error'));
    loginCount += 1;
    if (loginCount >= 3) {
        client.destroy();
    }
    return loginCount;
}


//处理心跳
function processHeadbeatFun(client, data) {
    client.headbeatReqId = data.reqId;
    client.headbeaPackTime = moment();
    clients[`${client.remoteAddress}:${client.remotePort}`] = client;
}


//心跳调度处理
function heartBeatInterval() {
    //心跳处理
    logger.info("监测:心跳监测启动");
    headbeatIntervalObj = setInterval(function () {
        for (const key in clients) {
            let client = clients[key];
            if (!client.loginStatus || client.headbeatReqId == 0) {
                continue;
            }
            let end_time = moment().subtract(headbeatTimeout, "seconds");

            let pack = `${headbeatPack.replace("{_reqId}",client.headbeatReqId).replace("{_time}",end_time.format('YYYY-MM-DD HH:mm:ss'))}`;
            logger.info(`发送心跳包:${pack}`);
            common.writeData(client, pack);

            if (client.headbeaPackTime < end_time) {
                clearAllInterval();
                client.destroy();
            }
        }
    }, headbeatPackInterval);
}


//告警调度处理
function listenAlertData() {
    //心跳处理
    logger.info("监测:监听告警数据开启");
    alertListenIntervalObj = setInterval(async function () {

    }, alertListenInterval);
}

//创建server
let server = net.createServer(function (client) {
    logger.info(' Client connection:');
    logger.info(' local= %s:%s', client.localAddress, client.localPort);
    logger.info(' remote= %s:%s', client.remoteAddress, client.remotePort);
    client.setTimeout(5000);
    client.setEncoding('utf8');

    client.loginStatus = false;
    client.headbeatReqId = 0;
    client.headbeaPackTime = moment();
    clients[`${client.remoteAddress}:${client.remotePort}`] = client;

    //登录次数
    let loginCount = 0;

    client.on('data', function (data) {

        if (data === null || data.length <= 0) {
            return;
        }

        logger.info('接收到数据:', data);

        //接收到消息  更新心跳时间
        data = `reqType=${data}`
        data = querystring.parse(data, ";");

        if (data === null) {
            return;
        }

        switch (data.reqType) {
            case "reqLoginAlarm":
                loginCount = loginProcessFun(client, loginCount, data);
                break;
            case "reqHeartBeat":
                processHeadbeatFun(client, data);
                break;
            case "closeConnAlarm":
                client.destroy();
                break;
            default:
                break;
        }
    });


    client.on('end', function () {
        logger.info('Client disconnected');
        server.getConnections(function (err, count) {
            logger.info('Remaining Connection:' + count);
        });
    });

    client.on('close', function () {
        delete clients[`${client.remoteAddress}:${client.remotePort}`];
        logger.info(`${client.remoteAddress}:${client.remotePort}断开连接`);
    });

    client.on('error', function (err) {
        delete clients[`${client.remoteAddress}:${client.remotePort}`];
        logger.info('Socket Error:', JSON.stringify(err));
    });


    client.on('timeout', function () {
        // logger.info('Socket Timed Out');
    });
});

//开始监听
server.listen(8011, function () {
    logger.info('Server listening: ' + JSON.stringify(server.address()));

    //监测任务
    heartBeatInterval();
    listenAlertData();

    server.on('close', function () {
        logger.info('Server Terminated');
    });
    server.on('error', function (err) {
        logger.info('Server Error:', JSON.stringify(err));
    });
});

```


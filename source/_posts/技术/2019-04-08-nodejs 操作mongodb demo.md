---
title: nodejs 操作mongodb demo
date: 2019/04/08 11:00:00
categories: 技术
toc: True
tags: [js]
---


### 前言
需要先安装mysql模块:
```shell
npm install mongodb -g
npm install q -g
```

### 代码
#### dbHelper.js
```js
var Q=require('q');
var MongoClient = require('mongodb').MongoClient;


/**
 * 创建数据库服务器并开发名为databaseName的数据库
 * @param host ip
 * @param port 端口
 * @param databaseName
 * @return  打开失败返回-1 ，成功返回database
 */
function openDatabase(){
    //创建数据库所在的服务器
    var deferred = Q.defer();
    var url = "mongodb://root:123456@192.168.99.100:27017/admin";
    MongoClient.connect(url, { useNewUrlParser: true }, function(err, db) {
        if (err) {
            console.log('连接数据库失败');
            deferred.reject(err);
        }
        else {
            console.log('连接数据库成功');
            var db = db.db("test");
            deferred.resolve([db,'stbinfo_test']);
        }
    });

    return deferred.promise;
}
/**
 * 连接数据集合
 * @param db 数据库
 * @param collectionName 数据集合名称
 * @return 成功返回collection，失败返回-1
 */
function openCollection(db,collectionName){
    var deferred = Q.defer();
    db.collection(collectionName,{safe:true},function(errcollection,collection){
        if(!errcollection){
            console.log('连接数据集合成功');
            deferred.resolve(collection);

        }else{
            console.log('连接数集合失败');
            deferred.reject(errcollection);
        }
    });
    return deferred.promise;

}
/**
 * 插入数据
 * @param collection
 * @param tmp 要插入的数据
 * @return 成功返回collection，失败返回-1
 */
function insertCollection(collection,tmp){
    //var tmp = {username:'hello',password:1};
    collection.insert(tmp,{safe:true},function(err, result){
        if(err){
            console.log('传入数据集合失败'+tmp);
            return -1;
        }else {
            console.log('插入数据集合成功'+result);

        }
    });
    return collection;
}
/**
 * 查询数据集合 没有条件
 * @param collection
 * @return 成功返回查询到的数据集合内容，失败返回-1
 */
function findCollectionNoCondition(collection){
    var deferred = Q.defer();
    collection.find().toArray(function(errfind,cols){
        if(!errfind){
            console.log('查询数据集合成功:'+cols);
            deferred.resolve({"collection":collection,"result":cols});
        }else {
            console.log('查询数据集合失败');
            deferred.reject(errfind);
        }
    });

    return deferred.promise;
}
/**
 * 查询数据集合 有条件
 * @param collection
 * @return 成功返回查询到的数据集合内容，失败返回-1
 */
function findCollectionHasCondition(collection,tmp){
    var deferred = Q.defer();
    collection.find(tmp).toArray(function(errfind,cols){
        if(!errfind){
            // console.log('查询数据集合成功'+JSON.stringify(cols));
            var result = cols;
            console.log(result);
            deferred.resolve({"collection":collection,"result":cols});
        }else {
            console.log('查询数据集合失败');
            deferred.reject(errfind);
        }
    });
    return deferred.promise;
}
/**
 * 删除数据集合
 * @param collection
 * @param tmp
 * @return 成功返回数据集合，失败返回-1
 */
function removeCollection(collection,tmp){
    //var tmp = {username:'hello',password:1};
    collection.remove(tmp,{safe:true},function(err, count){
        if(err){
            console.log('删除数据集合失败'+tmp);
            return -1;
        }else {
            console.log('删除数据集合成功'+count);
            return collection;
        }
    });
}


/**
 * 修改数据集合
 * @param collection
 * @param whereStr
 * @param updateStr
 * @return 成功返回数据集合，失败返回-1
 */
function updateManyCollection(collection,whereStr,updateStr){
    collection.updateMany(whereStr, updateStr, function(err, res) {
        if(err){
            console.log((new Date().getTime())+'更新数据集合失败'+err);
            return -1;
        }else {
            console.log((new Date().getTime())+'更新数据集合成功-'+':'+whereStr+res);
            return collection;
        }
    });
}



module.exports = {
    openDatabase,
    openCollection,
    insertCollection,
    findCollectionNoCondition,
    findCollectionHasCondition,
    removeCollection,
    updateManyCollection
}
```

#### main.js
```js
var dbHelper = require('./dbHelper');

dbHelper.openDatabase()
    .then(function (data) {
        return dbHelper.openCollection(data[0], data[1])
    })
    .then(function (collection) {
        return dbHelper.findCollectionHasCondition(collection,{'id':'-1'});
    }).then(function (data) {
        var result = data.result;
        return data.collection;
    })
    .done(function (data) {
        console.log('promise执行成功');
    }, function (err) {
        console.log("promise执行失败:" + err);
    });
```
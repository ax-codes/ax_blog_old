---
title: python3操作mysql帮助类
date: 2015/04/10 08:00:00
categories: 技术
toc: True
tags: python
---
## 前言
1. python3没有mysqldb,只有python2才有,所以我们在python使用的pymysql,安装命令
```shell
conda install PyMySQL
```
2. 代码是引用[https://www.cnblogs.com/dfcao/p/lightweight-python-mysql-class.html](https://www.cnblogs.com/dfcao/p/lightweight-python-mysql-class.html)的python2的LightMysql进行的修改,修改过程只需将Mysql模块替换成pymysql模块,和一些python3的语法

3. 如果你想使用python2操作mysql的话可以使用这个[https://www.cnblogs.com/dfcao/p/lightweight-python-mysql-class.html](https://www.cnblogs.com/dfcao/p/lightweight-python-mysql-class.html)可以参考这里的


## 代码
### sql
创建好数据库后,创建表,表结构sql如下:
```sql
-- ----------------------------
-- Table structure for customer
-- ----------------------------
DROP TABLE IF EXISTS `customer`;
CREATE TABLE `customer` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Cost` int(11) DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=latin1;
```

### 模块代码(MysqlHelper.py)
```python
# -*- coding: utf-8 -*-

import pymysql
import time
import re

class MysqlHelper:
    """Lightweight python class connects to MySQL. """

    _dbconfig = None
    _cursor = None
    _connect = None
    _error_code = '' # error_code from MySQLdb

    TIMEOUT_DEADLINE = 30 # quit connect if beyond 30S
    TIMEOUT_THREAD = 10 # threadhold of one connect
    TIMEOUT_TOTAL = 0 # total time the connects have waste

    def __init__(self, dbconfig):
        try:
            self._dbconfig = dbconfig
            self.dbconfig_test(dbconfig)
            self._connect = pymysql.connect(
                host=self._dbconfig['host'],
                port=self._dbconfig['port'],
                user=self._dbconfig['user'],
                passwd=self._dbconfig['passwd'],
                db=self._dbconfig['db'],
                charset=self._dbconfig['charset'],
                connect_timeout=self.TIMEOUT_THREAD)
        except pymysql.Error as e:
            self._error_code = e.args[0]
            error_msg = "%s --- %s" % (time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())), type(e).__name__), e.args[0], e.args[1]
            print(error_msg)

            # reconnect if not reach TIMEOUT_DEADLINE.
            if self.TIMEOUT_TOTAL < self.TIMEOUT_DEADLINE:
                interval = 0
                self.TIMEOUT_TOTAL += (interval + self.TIMEOUT_THREAD)
                time.sleep(interval)
                # return self.__init__(dbconfig)
            raise Exception(error_msg)
        self._cursor = self._connect.cursor(pymysql.cursors.DictCursor)

    def dbconfig_test(self, dbconfig):
        flag = True
        if type(dbconfig) is not dict:
            print('dbconfig is not dict')
            flag = False
        else:
            for key in ['host','port','user','passwd','db']:
                if key in dbconfig.items():
                    print("dbconfig error: do not have %s" % key)
                    flag = False
            if not 'charset' in dbconfig.items():
                self._dbconfig['charset'] = 'utf8'

        if not flag:
            raise Exception('Dbconfig Error')
        return flag

    def query(self, sql, ret_type='all'):
        try:
            self._cursor.execute("SET NAMES utf8")
            self._cursor.execute(sql)
            if ret_type == 'all':
                return self.rows2array(self._cursor.fetchall())
            elif ret_type == 'one':
                return self._cursor.fetchone()
            elif ret_type == 'count':
                return self._cursor.rowcount
        except pymysql.Error as e:
            self._error_code = e.args[0]
            print("Mysql execute error:",e.args[0],e.args[1])
            return False

    def dml(self, sql):
        '''update or delete or insert'''
        try:
            self._cursor.execute(sql)            
            type = self.dml_type(sql)
            # if primary key is auto increase, return inserted ID.
            if type == 'insert':
                insert_id = self._connect.insert_id()#必须在commit之前,不然会是0
                self._connect.commit()
                return insert_id
            else:
                self._connect.commit()
                return True
        except pymysql.Error as e:
            self._error_code = e.args[0]
            print("Mysql execute error:",e.args[0],e.args[1])
            return False

    def dml_type(self, sql):
        re_dml = re.compile('^(?P<dml>\w+)\s+', re.I)
        m = re_dml.match(sql)
        if m:
            if m.group("dml").lower() == 'delete':
                return 'delete'
            elif m.group("dml").lower() == 'update':
                return 'update'
            elif m.group("dml").lower() == 'insert':
                return 'insert'
        print("%s --- Warning: '%s' is not dml." % (time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())), sql))
        return False


    def rows2array(self, data):
        '''transfer tuple to array.'''
        result = []
        for da in data:
            if type(da) is not dict:
                raise Exception('Format Error: data is not a dict.')
            result.append(da)
        return result

    def __del__(self):
        '''free source.'''
        try:
            self._cursor.close()
            self._connect.close()
        except:
            pass

    def close(self):
        self.__del__()
```

### 引用代码
```python
from MysqlHelper import MysqlHelper

if __name__ == '__main__':

    # 配置信息，其中host, port, user, passwd, db为必需
    dbconfig = {'host':'127.0.0.1',
                'port': 3306,
                'user':'root',
                'passwd':'123',
                'db':'pytest',
                'charset':'utf8'}

    db = MysqlHelper(dbconfig) # 创建MysqlHelper对象，若连接超时，会自动重连

    # 查找(select, show)都使用query()函数
    sql_select = "SELECT * FROM Customer"
    result_all = db.query(sql_select) # 返回全部数据
    result_count = db.query(sql_select, 'count') # 返回有多少行
    result_one = db.query(sql_select, 'one') # 返回一行

    # 增删改都使用dml()函数
    sql_insert = "insert into Customer(Cost) values(20)"
    result_insert = db.dml(sql_insert)
    sql_update = "update Customer set Cost=2 where Id=2"
    result_update = db.dml(sql_update)
    # sql_delete = "delete from Customer where Id=2"
    # result_delete = db.dml(sql_delete)
    print(result_insert)
    db.close() # 操作结束，关闭对象
```
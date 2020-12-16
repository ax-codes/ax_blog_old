---
title: mysqld --user=root start 启动数据库报数据库文件损坏问题
date: 2018/12/21 20:00:00
categories: 技术
toc: True
tags: [linux,windows,docker,数据库]
---

### 前言
mysqld --user=root start 报错
>注意:两个-

### 报错日志
```shell
2013-09-02 16:18:46 2544 [Note] Plugin 'FEDERATED' is disabled.

2013-09-02 16:18:46 3e8 InnoDB: Warning: Using innodb_additional_mem_pool_size is DEPRECATED. This option may be removed in future releases, together with the option innodb_use_sys_malloc and with the InnoDB's internal memory allocator.

2013-09-02 16:18:46 2544 [Note] InnoDB: The InnoDB memory heap is disabled

2013-09-02 16:18:46 2544 [Note] InnoDB: Mutexes and rw_locks use Windows interlocked functions

2013-09-02 16:18:46 2544 [Note] InnoDB: Compressed tables use zlib 1.2.3

2013-09-02 16:18:46 2544 [Note] InnoDB: Not using CPU crc32 instructions

2013-09-02 16:18:46 2544 [Note] InnoDB: Initializing buffer pool, size = 16.0M

2013-09-02 16:18:46 2544 [Note] InnoDB: Completed initialization of buffer pool

2013-09-02 16:18:46 2544 [Note] InnoDB: Highest supported file format is Barracuda.

2013-09-02 16:18:47 2544 [Note] InnoDB: The log sequence numbers 1600614 and 1600614 in ibdata files do not match the log sequence number 1600644 in the ib_logfiles!

2013-09-02 16:18:47 2544 [Note] InnoDB: Database was not shutdown normally!

2013-09-02 16:18:47 2544 [Note] InnoDB: Starting crash recovery.

2013-09-02 16:18:47 2544 [Note] InnoDB: Reading tablespace information from the .ibd files...

2013-09-02 16:18:47 2544 [ERROR] InnoDB: Attempted to open a previously opened tablespace. Previous tablespace drupal/variable uses space ID: 2 at filepath: .\drupal\variable.ibd. Cannot open tablespace mysql/innodb_index_stats which uses space ID: 2 at filepath: .\mysql\innodb_index_stats.ibd

InnoDB: Error: could not open single-table tablespace file .\mysql\innodb_index_stats.ibd

InnoDB: We do not continue the crash recovery, because the table may become

InnoDB: corrupt if we cannot apply the log records in the InnoDB log to it.

InnoDB: To fix the problem and start mysqld:

InnoDB: 1) If there is a permission problem in the file and mysqld cannot

InnoDB: open the file, you should modify the permissions.

InnoDB: 2) If the table is not needed, or you can restore it from a backup,

InnoDB: then you can remove the .ibd file, and InnoDB will do a normal

InnoDB: crash recovery and ignore that table.

InnoDB: 3) If the file system or the disk is broken, and you cannot remove

InnoDB: the .ibd file, you can set innodb_force_recovery > 0 in my.cnf

InnoDB: and force InnoDB to continue crash recovery here.

I looked for a solution via google but it seems to be a problem just with the drupal database because it's able to connect with MySQL if I remove the database.

I hope someone could help me :(.
```
### 解决方法
1:找到的配置文件(my.cnf) 可以下面的命令查找
```shell
/usr/bin/mysql --verbose --help |grep -A 1 'Default options'
```
2:找到下面这行
```ini
# innodb_force_recovery = 2 
```
>如果没有则新增,打开这个会在mysql启动的时候自动修复损坏的数据库文件
3:把注释(#)删除然后保存退出
4:重新运行  mysqld --user=root start
5:发现没有报"****.ibd"的错误了
6:把mycnf的 innodb_force_recovery = 2 注释
7:service mysql start
```shell
ERROR! MySQL server PID file could not be found!
Starting MySQL. SUCCESS!
```
数据库启动成功!


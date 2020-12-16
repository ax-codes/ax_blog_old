---
title: linux crontab 使用python脚本定时执行命令
date: 2018/07/09 17:43:00
categories: 技术
toc: True
tags: python
---

### 使用nohup
```
nohup python -u scheduler.py > ../log/sync_table_partition.log 2>&1
```
使用-u参数，使得python不启用缓冲,直接输出内容
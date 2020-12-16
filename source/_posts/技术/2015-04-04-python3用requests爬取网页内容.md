---
title: python3用requests爬取网页内容
date: 2015/04/04 08:00:00
categories: 技术
toc: True
tags: python
---
### 代码
```python
# -*- coding: utf-8 -*-
import requests
from lxml import etree
import os
import codecs

r = requests.get('http://axss.gitee.io/')
r.encoding="utf-8" #解决中文乱码问题
html = r.text

selector = etree.HTML(html)
main = selector.xpath("/html/body/main/div[@class='content article-list']")[0]
for item in main:
    txt = item.xpath("./div/h1/a/text()")[0]
    print(txt)
```

### 总结
1. xpath 可以直接在谷歌浏览器f12 选择html标签复制
2. html文本需要先 etree 解析 
3. 解决获取到的文本中文乱码问题,给requert对象加上 r.encoding="utf-8"
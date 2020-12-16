---
title: error LNK2038 检测到“_ITERATOR_DEBUG_LEVEL”的不匹配项 值“0”不匹配值“2”(service.obj 中)
date: 2017/02/26 20:00:00
categories: 技术
toc: True
tags: [c语言,c++,windows]
---


### 前言
windows vs2012编译c++项目报错

### 报错log
```shell
1>  iconv-wrapper.lib(encoding.obj) : 找到 MSIL .netmodule 或使用 /GL 编译的模块；正在使用 /LTCG 重新启动链接；将 /LTCG 添加到链接命令行以改进链接器性能
1>LINK : warning LNK4075: 忽略“/INCREMENTAL”(由于“/LTCG”规范)
1>service.obj : warning LNK4075: 忽略“/EDITANDCONTINUE”(由于“/OPT:LBR”规范)
1>iconv-wrapper.lib(encoding.obj) : error LNK2038: 检测到“_ITERATOR_DEBUG_LEVEL”的不匹配项: 值“0”不匹配值“2”(service.obj 中)
1>iconv-wrapper.lib(encoding.obj) : error LNK2038: 检测到“RuntimeLibrary”的不匹配项: 值“MT_StaticRelease”不匹配值“MDd_DynamicDebug”(service.obj 中)
1>LINK : warning LNK4098: 默认库“LIBCMT”与其他库的使用冲突；请使用 /NODEFAULTLIB:library
1>E:\work\webserver-boost-sqm\platform\windows\\..\..\build\dbin\webserver-sqm-unicom-gd.exe : fatal error LNK1319: 检测到 2 个不匹配项
```

### 解决
检查链接库,可能原因是编译debug但是使用了release版本的库,或者编译release使用了debug版本的库
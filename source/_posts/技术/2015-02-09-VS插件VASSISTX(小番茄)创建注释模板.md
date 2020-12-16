---
title: VS插件VASSISTX(小番茄)创建注释模板
date: 2015/02/09 08:00:00
categories: 技术
toc: True
tags: [c语言,c++,csharp,.net/.net core,python,开发工具/插件]
---
## 前言
VASSISTX是vs的一款插件,可以大大提高程序的开发效率,VASSISTX的安装和破解可以自己百度,这里主要讲的是使用它的快速生成模板的功能

## 步骤
安装好VASSISTX后选择操作栏上的VASSISTX然后打开Visual Assist Options 选择Suggestions 再选择Edit VA Snippets 就能看到下图界面
![Edit VA Snippets](1.jpg)
我们需要new一个然后可以选择一个下方现有的模板复制到我们新增的模板里,可以按照自己的要求修改
![Edit VA Snippets](2.jpg)
最后输入Title和Shortcut，这个Shortcut是我们在启动命令(在vs界面输入的时候VASSISTX自动会检测,检测到我们只需选择后按tab或者enter建即可显示我们需要追加的模板)

## 常用注释格式
```c++
//1、生成文件头注释  
/************************************************************************** 
    *  @Copyright (c) $YEAR$, AX, All rights reserved. 
 
    *  @file     : $FILE_BASE$.$FILE_EXT$ 
    *  @version  : ver 1.0 
 
    *  @author   : AX 
    *  @date     : $YEAR$/$MONTH_02$/$DAY_02$ $HOUR_02$:$MINUTE$ 
    *  @brief    : $brief$ 
**************************************************************************/  
  
//2、生成函数功能注释  
/******************************************************** 
    *  @function :  
    *  @brief    :  $brief$ 
    *  @input    : 
    *  @output   : 
    *  @return   :  成功返回0，失败返回非0 
 
    *  @author   :  AX  $YEAR$/$MONTH_02$/$DAY_02$ $HOUR_02$:$MINUTE$ 
********************************************************/  
  
//3、生成类
//2、生成函数功能注释  
/******************************************************** 
    *  @class :  
    *  @brief    :  $brief$ 
    *  @author   :  AX  $YEAR$/$MONTH_02$/$DAY_02$ $HOUR_02$:$MINUTE$ 
********************************************************/  
  
//4、生成单行标记  
//-------By_AX_$YEAR$/$MONTH_02$/$DAY_02$ $HOUR_02$:$MINUTE$  
  
//5、生成多行标记  
/*-----------------By_AX_$YEAR$/$MONTH_02$/$DAY_02$ $HOUR_02$:$MINUTE$-----------------*/  
/*------------------------------------------------------------*/  
```
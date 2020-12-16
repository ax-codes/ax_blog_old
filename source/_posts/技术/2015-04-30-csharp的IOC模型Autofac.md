---
title: csharp的IOC模型Autofac
date: 2015/04/30 08:00:00
categories: 技术
toc: True
tags: [csharp,.net/.net core]
---
### 前言
1. Autofac是一款IOC框架，比较于其他的IOC框架，如Spring.NET，Unity，Castle等等所包含的，它很轻量级性能上非常高。
2. 官网:[http://autofac.org/](http://autofac.org/)
3. 源码:[https://github.com/autofac/Autofac](https://github.com/autofac/Autofac)
4. 理解:在web层引用业务层,如果web里多个地方创建了这个对象,那么业务改了之后,在new的地方需要改很多地方,但是如果用了依赖注入那么只需要改autofac注册这个类到对象的地方就行,不用每一个使用业务层对象的地方都要改,因为web层使用的都直接是接口对象,没有new了,同理,其他层也是一样
5. ioc:依赖注入
6. 备注:最新版本下载可以看到，包括源码，示例文档，与之相关的测试项目，生成的DLL文件，其他文档


### ioc实际应用场景
以两种日志记录和数据库使用两种场景来分析    
1. 日志记录：有时需要调试分析，需要记录日志信息，这时可以采用输出到控制台、文件、数据库、远程服务器等；假设最初采用输出到控制台，直接在程序中实例化ILogger logger = new ConsoleLogger()，但有时又需要输出到别的文件中，也许关闭日志输出，就需要更改程序，把ConsoleLogger改成FileLogger或者NoLogger，此时不断的更改代码，就显得心里不好了，如果采用依赖注入，就显得特别舒畅

2. 数据库操作：几乎任何项目都离不开数据库的使用，数据库种类特别多：oracle、mysql、sqlserver、informix、postgresql... ...，数据库语法也不尽相同，假如开始使用的是oracle，有一天改成了postgresql，这时采用依赖注入就显得圆润的多

### ioc优点
1. 传统的代码，每个对象负责管理与自己需要依赖的对象，导致如果需要切换依赖对象的实现类时，需要修改多处地方。同时，过度耦合也使得对象难以进行单元测试。
2. 依赖注入把对象的创造交给外部去管理,很好的解决了代码紧耦合（tight couple）的问题，是一种让代码实现松耦合（loose couple）的机制。
3. 松耦合让代码更具灵活性，能更好地应对需求变动，以及方便单元测试。

### ioc缺点
1. 在java语言中基本采用反射的方式来实现依赖注入，在一定程度会影响性能
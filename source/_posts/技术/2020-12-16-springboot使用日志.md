---
title: springboot使用日志
date: 2020/12/16 20:00:00
categories: 技术
toc: True
tags: [java, spring]
---

### 前言

Spring Boot 使用 Apache Commons 日志记录所有内部日志记录,Spring Boot 的默认配置为使用 Java Util Logging,Log4j2 和 Logback 提供了支持.使用这些,我们可以配置控制台日志以及文件日志.如果您使用的是 Spring Boot Starters,则 Logback 将为日志记录提供良好的支持.此外,Logback 还提供了对 Common Logging,Util Logging,Log4J 和 SLF4J 的良好支持

### 配置

在 classpath 下新增 logback.xml,并添加下面内容

```xml
<?xml version="1.0" encoding="UTF-8"?>
<configuration debug="true">

    <!--用springProperty来配置的话，可以直接读取properties文件-->
    <springProperty scope="context" name="LOG-DIR" source="log.dir"/>
    <!--<property name="LOG-DIR" value="/home/admin/logs"/>-->
    <property name="APP-NAME" value="coupon"/>
    <property name="LOG-PATTERN" value="%red(%d{yyyy-MM-dd HH:mm:ss}) %green([%thread]) %highlight(%-5level) %boldMagenta(%logger) - %cyan(%msg%n)"/>

    <!--控制台-->
    <appender name="STDOUT" class="ch.qos.logback.core.ConsoleAppender">
        <encoder>
            <!--<charset>UTF-8</charset>-->
            <pattern>${LOG-PATTERN}</pattern>
        </encoder>
    </appender>

    <!--日志文件-->
    <appender name="FILE-ALL" class="ch.qos.logback.core.rolling.RollingFileAppender">
        <!--滚动策略，按照时间滚动 TimeBasedRollingPolicy-->
        <rollingPolicy class="ch.qos.logback.core.rolling.TimeBasedRollingPolicy">
            <!--文件路径,定义了日志的切分方式,把每一天的日志归档到一个文件中,以防止日志填满整个磁盘空间-->
            <FileNamePattern>${LOG-DIR}/${APP-NAME}/${APP-NAME}-%d{yyyyMMdd}.log</FileNamePattern>
            <!--只保留最近10天的日志-->
            <maxHistory>10</maxHistory>
            <!--用来指定日志文件的上限大小，那么到了这个值，就会删除旧的日志-->
            <!--<totalSizeCap>1GB</totalSizeCap>-->
        </rollingPolicy>
        <!--日志输出编码格式化-->
        <encoder>
            <!--<charset>UTF-8</charset>-->
            <pattern>${LOG-PATTERN}</pattern>
        </encoder>
    </appender>

    <!-- ERROR日志文件 -->
    <appender name="FILE-ERROR" class="ch.qos.logback.core.rolling.RollingFileAppender">
        <filter class="ch.qos.logback.classic.filter.LevelFilter">
            <!--过滤 ERROR-->
            <level>ERROR</level>
            <onMatch>ACCEPT</onMatch>
            <onMismatch>DENY</onMismatch>
        </filter>
        <!--滚动策略，按照时间滚动 TimeBasedRollingPolicy-->
        <rollingPolicy class="ch.qos.logback.core.rolling.TimeBasedRollingPolicy">
            <!--文件路径,定义了日志的切分方式——把每一天的日志归档到一个文件中,以防止日志填满整个磁盘空间-->
            <FileNamePattern>${LOG-DIR}/${APP-NAME}/${APP-NAME}-error-%d{yyyyMMdd}.log</FileNamePattern>
            <!--只保留最近10天的日志-->
            <maxHistory>10</maxHistory>
            <!--用来指定日志文件的上限大小，那么到了这个值，就会删除旧的日志-->
            <!--<totalSizeCap>1GB</totalSizeCap>-->
        </rollingPolicy>
        <!--日志输出编码格式化-->
        <encoder>
            <!--<charset>UTF-8</charset>-->
            <pattern>${LOG-PATTERN}</pattern>
        </encoder>
    </appender>

    <root level="INFO">
        <appender-ref ref="STDOUT"/>
        <appender-ref ref="FILE-ALL"/>
        <appender-ref ref="FILE-ERROR"/>
    </root>

    <!--<logger name="com.jjld.coupon.repository" level="DEBUG"/>-->
    <!--<logger name="com.jjld.coupon.mapper" level="DEBUG"/>-->

</configuration>
```

### 使用

```java
package com.example.spring_crm;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class SpringCrmApplication{

    private static final Logger logger = LoggerFactory.getLogger(SpringCrmApplication.class);


    public static void main(String[] args) {
        logger.info("this is a info message");
        logger.warn("this is a warn message");
        logger.error("this is a error message");
        SpringApplication.run(SpringCrmApplication.class, args);
    }
}

```

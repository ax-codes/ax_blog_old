---
title: ajax调用webservice报错
date: 2015/03/08 08:00:00
categories: 技术
toc: True
tags: .net/.net core
---
## ajax调用webservice报错
### 异常报告
```js
XMLHttpRequest cannot load http://localhost:8098/webApi.asmx/stockData. No 'Access-Control-Allow-Origin' header is present on the requested resource. Origin 'http://localhost:26883' is therefore not allowed access.
```

### 解决
在web服务器的config的configuration节点加上下面的配置就行
```xml
<system.webServer>
    <httpProtocol>
      <customHeaders>
        <add name="Access-Control-Allow-Origin" value="*" />
        <add name="Access-Control-Allow-Headers" value="Content-Type" />
      </customHeaders>
    </httpProtocol>
</system.webServer>
```
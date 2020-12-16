---
title: nginx https 配置
date: 2019/12/28 10:00:00
categories: 技术
toc: True
tags: [开发工具/插件, linux]
---

### 前言

nginx https 配置
证书:我的证书是阿里云提供的免费一年的,具体下载方式可以百度

### 配置

在 nginx 新增一个 server 节点配置

```js
server          # SSL配置
    {
        listen 443;
        server_name www.zgaiyu.com zgaiyu.com;           # 改成你的域名
        ssl on;
        root /usr/local/wx_app_api/;
        ssl_certificate 1_www.zgaiyu.com_bundle.crt;     # 改成你的证书名称
        ssl_certificate_key 2_www.zgaiyu.com.key;          # 改成你的证书名称
        ssl_session_timeout 5m;
        ssl_protocols TLSv1 TLSv1.1 TLSv1.2;
        ssl_ciphers ECDHE-RSA-AES128-GCM-SHA256:HIGH:!aNULL:!MD5:!RC4:!DHE;
        ssl_prefer_server_ciphers on;


        # Load configuration files for the default server block.
        include /etc/nginx/default.d/*.conf;

        location ^~/wx_app_api/ {
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
            proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            #配置反向代理 注意:最后一定要加上/不然跳转链接是http://127.0.0.1:8080/wx_app_api/
            proxy_pass http://127.0.0.1:8080/; #这个8080是我web api的端口
        }
    }
```

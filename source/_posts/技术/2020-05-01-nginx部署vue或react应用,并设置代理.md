---
title: nginx部署vue或react应用,并设置代理
date: 2020/05/01 20:00:00
categories: 技术
toc: True
tags: [js, 开发工具/插件, 效率工具/插件, 其他工具/插件]
---

### 前言

nginx 部署 vue 或 react 应用,并设置代理

### 配置

```json
server {
        listen       9000;
        server_name  localhost;
        location /{
            root   F:/learning/webpack/react-typescript-boilerplate/dist;//react编译的dist包路径
            index  index.html index.htm;
            try_files $uri $uri/ /index.html =404;
        }
        location /api/ {
              proxy_pass http://127.0.0.1:3000/api/;#转发请求的地址
              proxy_connect_timeout 6000;#链接超时设置
              proxy_read_timeout 6000;#访问接口超时设置
        }
    }
```

### 重启 nginx

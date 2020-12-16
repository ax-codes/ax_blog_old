---
title: python使用tcp socket例子
date: 2018/05/17 11:00:00
categories: 技术
toc: True
tags: python
---

```python
# -*- coding: utf-8 -*
import socket
import threading
import time
import sys

type = sys.getfilesystemencoding()     #获取系统默认编码类型

# 3、tcp的通信
def tcp_server():
    # 1、创建套接字
    tcp_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 2、绑定本地信息
    address = ('127.0.0.1', 7788)
    tcp_fd.bind(address)
    # 3、使用socket创建的套接字默认的属性是主动的，使用listen将其变为被动的，这样就可以接收别人的链接了
    tcp_fd.listen(5)

    while True:
        # 4、如果有新的客户端来链接服务器，那么就产生一个新的套接字专门为这个客户端服务器
        # newSocket用来为这个客户端服务
        # tcpSerSocket就可以省下来专门等待其他新客户端的链接
        new_fd, client_address = tcp_fd.accept()
        # 5、接收对方发送过来的数据，最大接收1024个字节
        receive_data = new_fd.recv(1024)
        print('server: receive data:', receive_data.decode(encoding='utf-8'))
        # 6、发送一些数据到客户端
        new_fd.send(b"thank you !")
        # print(new_fd.getpeername())
        # print(new_fd.getsockname())
        # 7、关闭为这个客户端服务的套接字，只要关闭了，就意味着为不能再为这个客户端服务了，如果还需要服务，只能再次重新连接
        new_fd.close()

    # 关闭监听套接字，只要这个套接字关闭了，就意味着整个程序不能再接收任何新的客户端的连接
    tcp_fd.close()


def tcp_client(num):
    # 1、创建socket
    tcp_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 2、链接服务器
    server_address = ('127.0.0.1', 7788)
    tcp_fd.connect(server_address)
    # 3、发送数据
    tcp_fd.send(b'hello world.')
    # 4、接收对方发送过来的数据，最大接收1024个字节
    receive_data = tcp_fd.recv(1024)
    print('client-%s receive data:' % num, receive_data.decode(encoding='utf-8'))
    # 5、关闭套接字
    # print(tcp_fd.getpeername())
    # print(tcp_fd.getsockname())
    tcp_fd.close()

if __name__ == "__main__":
    t1 = threading.Thread(target=tcp_server)
    t1.start()
    time.sleep(5)
    th = []
    for i in range(5):
        t = threading.Thread(target=tcp_client, args=(i,))
        t.start()
        time.sleep(1)
        th.append(t)
    for t in th:
        t.join()
```
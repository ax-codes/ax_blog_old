#! python2
# -*- coding: utf-8 -*
import os
import sys

type = sys.getfilesystemencoding()  # 获取系统默认编码类型
print('===开始执行===').decode('utf-8').encode(type)  # 对打印内容先解码再编码
print('===hexo clean .===')
os.system("hexo clean")
print('===hexo g===')
os.system("hexo g")
print('===git add .===')
os.system("git add .")
print("===git commit -am 'ax'===")
os.system("git commit -am 'ax'")
print('===git push===')
os.system("git push origin hexo")
print('===hexo d===')
os.system("hexo d")
print('===执行结束===').decode('utf-8').encode(type)  # 对打印内容先解码再编码

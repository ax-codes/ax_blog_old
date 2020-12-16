# -*- coding: utf-8 -*
import os
import sys

type = sys.getfilesystemencoding()     #获取系统默认编码类型

print('===开始执行===').decode('utf-8').encode(type)    #对打印内容先解码再编码
print('===git pull origin master===')
os.system("git pull origin master")
print('===git merge remoter/origin/master===')
os.system("git merge remoter/origin/master")
print('===cd public===')
os.chdir('./public')
print('===git pull origin master===')
os.system("git pull origin master")
print('===git merge remoter/origin/master===')
os.system("git merge remoter/origin/master")
print('===执行结束===').decode('utf-8').encode(type)    #对打印内容先解码再编码
# -*- coding: utf-8 -*
import os
import sys

type = sys.getfilesystemencoding()     #获取系统默认编码类型

print('===开始执行===').decode('utf-8').encode(type)    #对打印内容先解码再编码
print('===git pull origin main===')
os.system("git pull origin main")
print('===git merge remoter/origin/main===')
os.system("git merge remoter/origin/main")
print('===cd public===')
os.chdir('./public')
print('===git pull origin main===')
os.system("git pull origin main")
print('===git merge remoter/origin/main===')
os.system("git merge remoter/origin/main")
print('===执行结束===').decode('utf-8').encode(type)    #对打印内容先解码再编码
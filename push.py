#! python2
# -*- coding: utf-8 -*
import os
import sys

print('===开始执行===')
os.system("hexo g")
print('===git add *===')
os.system("git add *")
print("===git commit -m 'ax'===")
os.system("git commit -m 'ax'")
print('===git push -u origin main===')
os.system("git push -u origin main")
print('===cd public===')
os.chdir('./public')
print('===git add *===')
os.system("git add *")
print("===git pull===")
os.system("git pull")
print("===git commit -m 'ax'===")
os.system("git commit -m 'ax'")
print('===git push -u origin main===')
os.system("git push -u origin main")
print('===执行结束===')

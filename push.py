#! python2
# -*- coding: utf-8 -*
import os
import sys

print('===开始执行===')
os.system("hexo g")
print('===git add .===')
os.system("git add .")
print("===git commit -m 'ax'===")
os.system("git commit -m 'ax'")
print('===git push origin master===')
os.system("git push origin master")
print('===cd public===')
os.chdir('.\\public')
print('===git add .===')
os.system("git add .")
print("===git commit -am 'ax'===")
os.system("git commit -am 'ax'")
print('===git push origin master===')
os.system("git push origin master")
print('===执行结束===')

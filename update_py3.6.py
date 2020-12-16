import os

print('===开始执行===')
print('===git pull origin master===')
os.system("git pull origin master")
print('===git merge remoter/origin/master===')
os.system("git merge remoter/origin/master")
print('===cd public===')
os.chdir('.\\public')
print('===git pull origin master===')
os.system("git pull origin master")
print('===git merge remoter/origin/master===')
os.system("git merge remoter/origin/master")
print('===执行结束===')
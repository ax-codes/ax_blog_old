# -*- encoding:utf-8 -*-
import os
import yaml
import time
import json
import random
import shutil

path="E:\\blog\\Hexo\\source\\_posts\\"
timestamp= [1406851200]
randDayNum = [1,10]
addTimestamp = 86400

filePaths=[]
def getFileList(path):
    filelist=os.listdir(path)#该文件夹下所有的文件（包括文件夹）
    for files in filelist:#遍历所有文件
        filedir=os.path.join(path,files)#原来的文件路径
        if os.path.isdir(filedir):#如果是文件夹则跳过
            getFileList(filedir)
        filename=os.path.splitext(files)[0]#文件名
        filetype=os.path.splitext(files)[1]#文件扩展名
        if filetype!=".md":
            continue
        filePaths.append({"filename":filename,"filedir":filedir,"path":path})

def interception(start_str, end_str, str):
        start = str.find(start_str)
        if start >= 0:
            start += len(start_str)
            end = str.find(end_str, start)
            if end >= 0:
                return {"statrt":start,"end":end,"data":str[start:end].strip()}

def editFile(filePaths,timestamp,randDayNum,addTimestamp):
    for item in filePaths:
        file = open(item["filedir"],'r+',encoding='utf-8')
        str = file.read() 
        yamlStr = interception("---","---",str)
        yamlObj = yaml.load(yamlStr["data"])
        dateObj = getDateStr(timestamp,randDayNum,addTimestamp)
        yamlObj["date"]=dateObj["dt"]
        remaining = str[yamlStr["end"]+3:len(str)].strip()
        str = praseStr(yamlObj,remaining)
        file.close()

        file = open(item["filedir"],'w+',encoding='utf-8')
        file.write(str)
        file.close()
        fileName = item["filename"]
        if fileName[0:10] != dateObj["dt2"]: 
            newName =item["path"]+"\\"+dateObj["dt2"]+fileName[10:len(fileName)]
            dirPath = item["filedir"][0:len(item["filedir"])-3]
            if os.path.exists(dirPath):
                shutil.move(dirPath,newName)
            shutil.move(item["path"]+"\\"+fileName+".md",newName+".md")

    
def praseStr(yamlObj,remaining):
    str = ""
    str +="---\n"
    str +="title: "+yamlObj["title"]+"\n"
    str +="date: "+yamlObj["date"]+"\n"
    str +="categories: "+yamlObj["categories"]+"\n"
    toc = "True"
    if yamlObj["toc"] == False:
        toc = "False"
    str +="toc: "+toc+"\n" 
    tags = yamlObj["tags"]
    if type(yamlObj["tags"]) == list:
        newtags=""
        newtags +="["
        for tag in tags:
            newtags+=tag
            newtags+=","
        newtags =newtags[:-1]
        newtags +="]"
        tags = newtags
    str +="tags: "+tags+"\n"
    str +="---\n"
    str += remaining
    return str

def getDateStr(timestamp,randDayNum,addTimestamp):
    rand = random.randint(randDayNum[0],randDayNum[1])
    timestamp[0] = timestamp[0]+(rand*addTimestamp)
    timeLocal = time.localtime(timestamp[0])
    dt = time.strftime("%Y/%m/%d %H:%M:%S",timeLocal)
    dt2 = time.strftime("%Y-%m-%d",timeLocal)
    return {"dt":dt,"dt2":dt2}


getFileList(path)
editFile(filePaths,timestamp,randDayNum,addTimestamp)
# getDateStr(timestamp)
# getDateStr(timestamp+86400)



        
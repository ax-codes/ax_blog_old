#-*- coding:utf-8 -*-

import sys
import io
import datetime
import os
import ConfigParser

class ctemplate:
    __fileName = ' '
    __title = ' '
    __tag = ' '
    __tags = ' '
    __categorie = ' '
    __categories = ' '
    __folder = ' '
    __is_create_folder = ' '
    __date = datetime.datetime.now()
    #__path = '.\\source\\_posts\\'
    __path = './`'
    __fileComments = {'title':' ',
                      'date':' ',
                      'categories':' ',
                      'toc':' ',
                      'tags':' '
    }

    __CommentsOrder = ('title','date','categories','toc','tags')
    def __init__(self,title,tags,categories,is_create_folder):
        self.__fileName = "{0}-{1}.md".format(self.__date.strftime('%Y-%m-%d'),title)
        self.__title = title
        self.__tag = tags
        self.__categorie = categories

        self.__folder = "{0}-{1}".format(self.__date.strftime('%Y-%m-%d'),title)
        self.__is_create_folder = is_create_folder


    def generateCommentsAtTop(self):
        self.__fileComments['title'] = self.__title
        self.__fileComments['date'] = self.__date.strftime('%Y/%m/%d hh:mm:ss')
        self.__fileComments['categories'] = self.__categorie
        self.__fileComments['toc'] = 'True'
        self.__fileComments['tags'] = '[{0}]'.format(self.__tag)

        comments = ('---\n')

        #find max length of string
        maxLen = 0
        for s in self.__CommentsOrder:
            if(len(s) > maxLen):
                maxLen = len(s)

        for k in self.__CommentsOrder:
            alignSpaceAmount = maxLen - len(k) + 4
            alignSpace = alignSpaceAmount * ' '
            comments += ( k + alignSpace + ": " + self.__fileComments[k] + '\n')

        comments += ('---\n\n')
        return comments

    def create(self):
        
        path = "{0}{1}".format(self.__path,self.__fileName)
        path = path.decode('utf-8')#因为文件名乱码,所以再解了一次码
        fh = open(path,'w')
        cm = self.generateCommentsAtTop()
        fh.write(cm)
        fh.close()

        if not self.__is_create_folder:
            folder = "{0}{1}".foamat(self.__path,self.__folder)
            folder = folder.decode('utf-8')#因为文件名乱码,所以再解了一次码
            os.makedirs(folder) 

        pass
   

    def createTemplatePairs(self):
        self.create()

    def check_param(self,tags,categories):
        result = True
        if categories!='技术' and categories!='生活' and categories!='常用':
            result = False
            
        pass

    
def load_conf():
        cf =ConfigParser.ConfigParser()
        cf.read("conf.ini")
        categorie_keys = cf.get('categories','categories_key').split(',')
        categories = cf.get('categories','categories_val')
        
        load_conf_obj = {"categories":categories}
        return load_conf_obj

if __name__ == '__main__':
    load_conf_obj = load_conf()
    for categories in load_conf_obj["categories"].split(","):
        
    categorie_show = "请选择文章大类:"+load_conf_obj["categories"]
    categorie = raw_input(categorie_show.decode("utf-8").encode("gbk"))
    # if len(categorie)<=0:
    #     categorie = 1
    # title = ""
    # categorie = ""
    # tag = ""
    # is_create_folder = ""
    # while True:
    #     title = raw_input(str("请输入文章标题:").decode("utf-8").encode("gbk"))
    #     if len(title)<=0:
    #         continue
    # categorie = raw_input(str("请选择文章大类:").decode("utf-8").encode("gbk"))
    # if len(categorie)<=0:
    #     categorie = 1
    # tag = raw_input(str("请选择文章小类:").decode("utf-8").encode("gbk"))
    # if len(tag)<=0:
    #     tag = 1
    # is_create_folder = raw_input(str("是否创建文件夹:1:否 2:是").decode("utf-8").encode("gbk"))
    # if len(is_create_folder)<=0:
    #     is_create_folder = 1
    # ct = ctemplate(title,tag,categorie,is_create_folder)
    # ct.createTemplatePairs()

    # if len(sys.argv) < 3  or len(sys.argv) > 4:
    #     sys.stderr.write("please input corret parameter")
    # else:
    #     #python 内部都是unicode编码,所以不管什么编码我们都要先转成unicode,然后再编码
    #     #eg:这里因为dos的默认是gbk 所以我们先解码 然后再编码成utf-8这样dos输入中文就不会乱码了
    #     # title = str(sys.argv[1]).decode('gbk').encode("utf-8")
    #     # tags = str(sys.argv[2]).decode('gbk').encode("utf-8")
    #     # categories = str(sys.argv[3]).decode('gbk').encode("utf-8")

    #     title = str(sys.argv[1])
    #     tags = str(sys.argv[2])
    #     categories = str(sys.argv[3])
                
    #     is_create_folder = False
    #     if len(sys.argv)>=5:
    #         is_create_folder = True
    #         ct = ctemplate(title,tags,categories,is_create_folder)
    #         ct.createTemplatePairs()
    pass
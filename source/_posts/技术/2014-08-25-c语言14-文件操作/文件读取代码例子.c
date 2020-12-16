#include <stdio.h>


void myfgetc()
{
    //单字符
    /*
      1:先赋值再读取  因为文件的置位是先读才会置位的（表示已经读取完了），而feof是根据标志位是否置位的，所以我们需要先读才能用feof来判断是否读取完成
   */
    FILE * fp=fopen("1.txt","r+");
    if(!fp)
        return -1;
    char buff;
    //错误的读取方法  会造成多读一个的效果
    //    while(!feof(fp))//fgetc和fgets都是返回
    //    {
    //    buff=fgetc(fp);
    //        printf("%c",buff);
    //    }

    //1：第一种验证结束的方法
    //    while((buff=fgetc(fp))&&!feof(fp))//fgetc和fgets都是返回
    //    {
    //        printf("%c",buff);
    //    }

    //2:第二种验证结束的方法
    //    while((buff=fgetc(fp))!=EOF)//fgetc和fgets都是返回
    //    {
    //        printf("%c",buff);
    //    }

    fclose(fp);
}

void myfgets()
{
    FILE * fp=fopen("1.txt","r+");
    if(!fp)
        return -1;
    char buff[1024];
    while(fgets(buff,1024,fp)!=NULL) //判断结束条件是否为null  遇到'\0'
    {
        printf("%s",buff);
    }
    return 0;
}

void myfread()
{
    FILE * fp=fopen("1.txt","r+");
    if(!fp)
        return -1;
    char buff[1024];
    while(fread((void*)buff,1,1,fp)>0) //注意每次读取的字节数量必须是最小单元，不然如果某次读取的时候没有读满会返回0 也就说明会少打印
    {
        printf("%s",buff);
    }
}

int main(void)
{

    return 0;
}

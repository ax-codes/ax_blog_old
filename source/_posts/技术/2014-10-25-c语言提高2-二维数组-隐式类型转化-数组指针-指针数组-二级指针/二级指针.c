#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二级以及多级指针的步长  所有的指针的步长都是4
int main5()
{
    int  * p;
    int ** pp;
    int *** ppp;
    printf("%p\t%p\n",p,p+1);
    printf("%p\t%p\n",pp,pp+1);
    printf("%p\t%p\n",ppp,ppp+1);
    return 0;
}

//初始化一级指针  也叫返回二级指针
void initPointer(char ** str)//先写char* 再是指针所以加上*
{
    *str=(char*)malloc(100);
}

int main4()
{
    char * str=NULL;
    initPointer(&str);//想要修改里面的数据必须传地址
    strcpy(str,"china!");
    printf("%s\n",str);
    return 0;
}

//改变指向  n级指针可以改变n-1下所有的指针的指向
int main3()
{
    int a=100;
    int * b=&a;
    int **c = &b;//c=&b  *c=b=&a **c=*b=a
    int d = 200;
    printf("%d\n",*b);
    //通过c来改变b的指向
    *c=&d;
    printf("%d\n",*b);
}


//二级指针
int main2()
{
    int a=100;
    int * b=&a;
    int **c = &b;//c=&b  *c=b=&a **c=*b=a
    printf("%d\n",a);
    *b=200;
    printf("%d\n",a);
    **c=300;
    printf("%d\n",a);
    return 0;
}

//指针的运算  1：地址的运算其实是计算相隔指定类型的个数  2：转化为基本类型则是计算相隔的字节数
int main1(void)
{
    int a[10];
    printf("a = %p\n",a);
    printf("a+1 = %p\n",a+1);
    printf("&a[9] - &a[4] = %d\n",&a[9] - &a[4]);//5
    printf("(int)&a[9]-(int)&a[4] = %d\n",(int)&a[9] -(int)&a[4]);//转化为int就是基本运算  就是隔了多少个字节就是多少   所以yin应该是5*4=20
    return 0;
}


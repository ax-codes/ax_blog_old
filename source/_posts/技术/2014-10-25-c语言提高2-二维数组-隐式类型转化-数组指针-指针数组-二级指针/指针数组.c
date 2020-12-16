#include <stdio.h>

void traveseArray(char ** array,int n)//array就是一个实参的数据 实参是地址 所以该形参也是地址
{
    for(int i=0;i<n;i++)
        printf("%s\n",*(array+i));
}

//常见的处理指针数组的方法  在数组的末尾加上NULL作为结束标识
void traveseArray2(char ** array,int n)//array就是一个实参的数据 实参是地址 所以该形参也是地址
{
     while(*array)
        printf("%s\n",*(array++));
}
int main(void)
{
    char * pArray[] = {"apple","pear","banana","orange","pineApple",NULL};
    traveseArray2(&pArray,5);//指针数组
    return 0;
}


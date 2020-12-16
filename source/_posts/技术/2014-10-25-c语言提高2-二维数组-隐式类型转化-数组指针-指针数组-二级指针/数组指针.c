#include <stdio.h>

//数组指针：定义：本质上都是指针，只不过指向是指向数组
//常见的数组指针：不管是几维数组，他们的数组名本质上都是数组指针：常见错误：一级数组取地址等同于数组指针，不是二级指针
int main(void)
{
    int array[10]={1,2,3,4,5,5,6,6,4,5};
    int (*p)[10] =array;
    for(int i =0 ;i<10;i++)
        printf("%d\n",array);
    return 0;
}


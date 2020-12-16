#include <stdio.h>



//int(*arr)[4]的推演  本来传递一维数组应该是 int [4] * arr 和 行  所以  int [4] * arr=>int * arr[4]（指针数组）=>int(*arr)[4]（数组指针）
void deliver2DArr(int (*arr) [4],int n)//
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",*(*(arr+i)+j));//*(*(array+i)+j)：先取出行 *(array+i) =array[i] 再取出列
        }
        putchar(10);
    }
}

//将二维数组做为参数，二维名的本质是个数组指针，所以将二维数组做为参数传递的形参也应该是个数组指针类型
int main5()
{
    int array[3][4]={1,2,3,4,5,5,6,6,4,5,6,7,8,9};//
    deliver2DArr(array,3);//二维数组名就是一个数组指针  只不过类型是  int [4]  如果传递一个一维数组 int arr[4] 就是int * 加4
    return 0;
}


//遍历二维数组的方法
int main4()
{
    int array[3][4]={1,2,3,4,5,5,6,6,4,5,6,7,8,9};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",*(*(array+i)+j));//*(*(array+i)+j)：先取出行 *(array+i) =array[i] 再取出列
        }
        putchar(10);
    }
    return 0;
}

//用一维数组的方式来访问二维数组  因为内存的存储机制是线性的
int main3(void)
{
    int array[3][4]={1,2,3,4,5,5,6,6,4,5,6,7,8,9};
    int * p=(int*)array;//array表示该数组的首元素的首地址
    for(int i=0;i<12;i++)
        printf("%d\n",*(p+i));
    return 0;
}

int main2(void)
{
    //    int array[10]={1,2,3,4,5,5,6,6,4,5};
    //    printf("&array=%p\n",&array);//整体
    //    printf("&array+1=%p\n",&array+1);
    //    printf("array=%p\n",array);//一维数组名  类型是int  加一加的是int
    //    printf("array+1=%p\n",array+1);
    //    printf("&array[0]=%p\n",&array[0]);//& 和 []刚好抵消  所以&array[0]=array 所以类型是int 所以加一加的是int类型
    //    printf("&array[0]+1=%p\n",&array[0]+1);


    //int [4] array[3]  所有的数组名加减都理解成一维数组名来理解
    int array[3][4]={1,2,3,4,5,5,6,6,4,5,6,7,8,9};
    printf("&array=%p\n",&array);//整体性
    printf("&array+1=%p\n",&array+1);

    printf("array=%p\n",array);//一个一维数组名   类型是int[4] 所以加一加的是int[4]
    printf("array+1=%p\n",array+1);

    printf("array[0]=%p\n",array[0]);//一个一维数组名  类型是int  所以加一加的是int
    printf("array[0]+1=%p\n",array[0]+1);
    return 0;
}

int main1(void)
{
    int array[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    printf("*(*(&array[0]+1))= %d\n",*(*(&array[0]+1)));//array[0]相当于是个二维数组的第一个数组名  &array对数组名引用是一个数组指针  然后数组指针加减加的是整体   对数组指针解引用就是一个一维指针  然后再对一维指针进行解引用就是取值




    printf("*(array[0]+1) = %d\n",*(array[0]+1));//array[0][0]所指向的类型是int所以加上4
    printf("*(array[0]+1) = %d\n",array[0][1]);//2
    //如何 array 过度到 array[0]
    printf("*array = %p\n",*array);//array = &array[0] *&array[0]就是一个一维指针  一维指针加一
    printf("*array + 1 = %p\n",*array + 1);//加的是int类型大小  一维指针
    printf("array[0] + 1 = %p\n",array[0] +1);//arrar[0]=&array[0][0] 是个数组指针  类型是int
    return 0;
}


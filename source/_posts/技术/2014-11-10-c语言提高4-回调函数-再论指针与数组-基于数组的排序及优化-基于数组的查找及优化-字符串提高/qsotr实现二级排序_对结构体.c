#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[30];
	float score;
}Stu;
 
int callBackStuSort(void * stu1, void * stu2)//这里的形参都是void*型   我们需要将其转化为我们想要的类型
{
	if (strcmp((*(Stu*)stu1).name, (*(Stu*)stu2).name) > 0)
		return 1;
	else if (strcmp((*(Stu*)stu1).name, (*(Stu*)stu2).name) < 0)
	{
		if ((*(Stu*)stu1).score>(*(Stu*)stu1).score)
			return 1;
		else if ((*(Stu*)stu1).score < (*(Stu*)stu1).score)
			return -1;
	}
}
 
//对结构体数据进行二次排序
int main()
{
	Stu  stu[] = { { "aaa", 23.5 }, { "xxx", 45.6 }, { "bbb", 89 }, { "xxx", 23.4 }, { "yyy", 100 } };
	qsort(stu, sizeof(stu) / sizeof(stu[0]), sizeof(stu), callBackStuSort);//第一个需要排序的对象  第二个范围  第三个步长  第四个回调函数 
	for (int i = 0; i < 5; i++)
	{
		printf("name=%s\score=%f\n", stu[i].name, stu[i].score );
	}
	return 0;
}

int callBackFunc1(void * pa, void * pb)  //传进的参数是char** 本来数据是char* 但是qsort取数据取的是保存数据的地址 所以最后传入的类型是char**
{ 
	return strcmp(*(char**)pa , *(char**)pb)>0 ? 1 : -1;//需要转化为
}

//自己实现的对指针数组进行排序deep方法
void myStrSort(char ** strArr, int len)//数组指针用二级指针接收
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (callBackFunc1(*(strArr + j), *(strArr + j + 1))>0)
			{
				 //指针不能异或操作
				char*temp = *(strArr + j);
				*(strArr + j) = *(strArr + j + 1);//直接改变里面的地址   字符串的首地址不能移动  但是*(strArr+j)不是arr[0] 而是保存了arr[0]的地址的空间
				*(strArr + j + 1) = temp;
			}
		}
	}
}

//对指针数组进行排序
int main2()
{
	char * arr[6] = {"apple","micsoft","goole","taobao","jindon","baidu"};
	myStrSort(arr, 6);
	//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), callBackFunc1);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s\n", *(arr + i));
	}
	return 0;
}

int callBackFunc(void * pa,void * pb)//qsort传入的类型是&int  
{
	return *((int*)pa) < *((int*)pb) ? 1 : -1;
}

int main1()
{
	int arr[10] = {9,2,4,5,3,2,4,4,6,7};
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), callBackFunc);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d\n", *(arr + i));
	}
	return 0;
}
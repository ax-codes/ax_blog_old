#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h> 

int delChar(char * str,int n ,int  len)
{
	memmove(str+n,str+n+1,(len-(n+1))*sizeof(*str));//1：目标源  表示需要复制到哪   2：数据源：表示需要从哪里复制  3：操作字节数：表示需要操作源数据的字节个数
	return len - 1;
}
 
//内存操作函数：不关心内容的结束标识 ， 每个函数的最后一个参数都是一个length表示需要操作的字节数 记住  内存操作函数是以字节为单位来操作的
int main()
{
	//mempy 
	//int a[10] = { 1, 2, 3, 4, 5, 0, 6, 7, 8, 9 }; //整型数组间的拷贝
	//int b[10];
	//memcpy(b, a, 10*sizeof(a[0]));//记住 内存操作函数是以字节为单位的
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n",b[i]);
	//}
	//char a[100] = "dfewfew\0fw"; //整型数组间的拷贝
	//char b[100];
	//memcpy(b, a,sizeof(a));//记住 内存操作函数是以字节为单位的   并且会将\0这些特殊字符都进行拷贝  
	//printf("%s\n", b);

	//memmove 
	//char a[100] = "1234567890"; //整型数组间的拷贝
	//int len = strlen(a);
	//int num = delChar(a,2,len);
	//printf("%s\n",a);

	//memcmp
	//	比较两段空间的前 n 个字节，其它逻辑等同于 strcmp。
	//	memchr
	//	查找一段空间中的一个字符，若存在则返回，所查找到字符的指针，若无，返回

	//memset :初始化一段空间内的内容  注意这些内存操作函数 操作的最小单元都是字节

	int arr[10];
	memset(arr, 1, sizeof(arr));//表示将每一位都制为01   所以 //hex 01010101 -> dec 16843009
	for (int i = 0; i <10; i++)
	{
		printf("%d\n",*(arr+i));
	}
	return 0;
}

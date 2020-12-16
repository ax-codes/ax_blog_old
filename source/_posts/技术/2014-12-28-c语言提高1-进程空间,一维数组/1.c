#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testPointer(int ** num)
{
	**num = 200;
}

int main1()
{
	int a = 100;
	int * b = &a;
	printf("%d\n", a);
	testPointer(&b);
	printf("%d\n", a);
	return 0;
}

char * createOnePointer()
{
	return  (char*)malloc(100);
}

//参数返回一级指针
int main2()
{
	char * p = createOnePointer();
	if (NULL == p)
		exit(0);
	strcpy(p, "china  !");
	printf("%s", p);
	free(p);
	return -1;
}

void createTowPointer(char ** ch)//得到的是p的地址
{
	//ch=&p  *ch = p
	*ch = (char*)malloc(100);
}

//参数返回一二级指针
int main3()
{
	char * p = NULL;
	createTowPointer(&p);
	strcpy(p, "china  !");
	printf("%s", p);
	return -1;
}

//将两个有序的数组加进一个新的数组  并且保持有序
int  main4()
{
	int a[3] = { 1, 3, 5 };
	int b[5] = { 2, 5, 6, 8, 10 };
	int c[8];

	int a_index = 0;
	int b_index = 0;
	int c_index = 0;
	while (a_index < 3 && b_index<5)
	{
		if (a[a_index]>b[b_index])
		{
			c[c_index] = b[b_index];
			c_index++;
			b_index++;
		}
		else if (a[a_index] < b[b_index])
		{
			c[c_index] = a[a_index];
			c_index++;
			a_index++;
		}
		else
		{
			c[c_index] = a[a_index];
			c_index++;
			a_index++;
			c[c_index] = b[b_index];
			c_index++;
			b_index++;
		}
	} 

	while (a_index < 3)
	{
		c[c_index++] = a[a_index++];
	}

	while (b_index < 5)
	{
		c[c_index++] = b[b_index++];
	}
	for (int i = 0; i < 8; i++)
		printf("%d\n", *(c + i));
}

//求最值
int main5()
{
	int arr[5] = { 2, 5, 6, 8222, 10 };
	//假设第一个是最大值
	for (int i = 1; i < 5; i++)
	{
		if (arr[0] < arr[i])
			arr[0] = arr[i];
	}
	printf("数组的最大值是：%d\n",*(arr+0));
	return 0;
}

//求次最值
int main()
{
	int arr[5] = { 2, 5, 622, 2, 10 };

	//假设arr[0]总是最大值   arr[1]总是次大值
	for (int i = 0; i < 5; i++)
	{
		if (arr[i]>arr[0])
		{
			arr[1] ^= arr[0];
			arr[0] ^= arr[1];
			arr[1] ^= arr[0];
			arr[i] ^= arr[0];
			arr[0] ^= arr[i];
			arr[i] ^= arr[0];
		}
		if (arr[i] > arr[1] && arr[i] < arr[0])
		{
			arr[1] ^= arr[i];
			arr[i] ^= arr[1];
			arr[1] ^= arr[i];
		}
	}
	printf("数组的最大值是：%d\n", *(arr + 0));
	printf("数组的次大值是：%d\n", *(arr + 1));
	return 0;
}


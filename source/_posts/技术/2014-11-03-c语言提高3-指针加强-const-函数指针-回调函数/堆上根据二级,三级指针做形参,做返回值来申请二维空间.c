#include <stdlib.h>
#include <stdlib.h>

void   param2dPointer_3(int *** p,int size, int row, int line)
{
	*p = (void**)malloc(4*row);
	for (int i = 0; i < row; i++)
	{
		*(*p + i) = (void*)malloc(4 * line);
	}
}

//3:三级指针作参数输出 返回二维空间
int main()
{
	//1:一级指针作返值输出   因为是一级指针做返回值 所以只能考虑指针数组  我们返回还是返回一维的  但是我们可以解释为指针数组
	int row = 3;
	int line = 4;
	int ** p = NULL;
	param2dPointer_3(&p,sizeof(int),row, line);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			*(*(p + i) + j) = i + j;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d\t",*(*(p+i)+j));
		}
		putchar(10);
	}
	return 0;
}

//2:二级指针作返值输出  返回二维空间
void ** param2dPointer_2(int size, int row, int line)
{
	void ** p = (void**)malloc(4*row);
	for (int i = 0; i < row; i++)
	{
		*(p+i) = (void*)malloc(4 * line);
	}
	return p;
}

int main2()
{
	//1:一级指针作返值输出   因为是一级指针做返回值 所以只能考虑指针数组  我们返回还是返回一维的  但是我们可以解释为指针数组
	int row = 3;
	int line = 4;
	int ** arr = param2dPointer_2(sizeof(int),row,line);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j< row; j++)
		{
			*(*(arr + i) + j) = i + j;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j< row; j++)
		{
			printf("%d\t", *(*(arr + i) + j));
		}
		putchar(10);
	}
	return 0;
}

//1:一级指针作返值输出  返回二维空间
void * param2dPointer(int size,int row,int line)
{
	void * p = (void*)malloc(size*row*line);
	return p;
}

int main1()
{
	//1:一级指针作返值输出   因为是一级指针做返回值 所以只能考虑指针数组  我们返回还是返回一维的  但是我们可以解释为指针数组
	int row = 3;
	int line = 4;
	int (*p)[4]=(int (*)[4])param2dPointer(sizeof(int),row,line);//int [4] *  所谓的指针数组  其实就是二维或者多维数组名
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < line; j++)
		{
			*(*(p + i)+j)= i + j;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j< line; j++)
		{
			printf("%d\t", *(*(p + i) + j));
		}
		putchar(10);
	}
	return 0;
}
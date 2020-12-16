#include <stdlib.h>
#include <stdio.h>


//快速排序就是  首先确认一个符号位  然后比符号位大的放右边   比符号位小的放左边
void quickSort(int * p, int low, int high)
{
	if (low < high)//定义递归的结束标识
	{
		int flag = p[low];
		int  l = low;
		int h = high;
		while (l<h)
		{
			//从右边开始比较 因为左边的开头位已经确认为标识位
			while (flag<=p[h]&&l<h)
				h--;
			p[l] = p[h];//将比符号位小的放到符号位
			while (flag >= p[l] && l < h)
				l++;
			p[h] = p[l];
		}
		p[l] = flag;//将符号位数据放到最后确认的位置
		//左移动
		quickSort(p, low, h-1);
		quickSort(p, l+1, high);//右移
	}
}
 
//1：选择排序 基本版  :每个元素跟后面的所有的比较
void xzSort(int * arr, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (arr[i]>arr[j])
			{
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
	}
}

//2：选择排序优化版    比而不换  原理：首先记录外层循环下标  如果发生改变 则取到的是最小值   所以如果idx发生变化则进行交换  反之则不用
void xzSortS(int * arr, int len)  
{
	for (int i = 0; i < len - 1; i++)
	{
		int idx = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[idx]>arr[j])
			{
				idx = j;
			}
		}
		if (idx != i)
		{
			arr[i] ^= arr[idx];
			arr[idx] ^= arr[i];
			arr[i] ^= arr[idx];
		}
	}
}

//2：冒泡排序 基本版   
void mpSort(int * arr, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
			}
		}
	}
}

//2：冒泡排序 优化版  : 
void mpSortS(int * arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				flag = 1;
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
			}
		}
		if (!flag)//如果flag没有变化 说明数组已经是有序的  不用再遍历 直接退出  
			break;
	}
}


int main()
{
	//printf("%d\n",sizeof("8822228"));
	int arr[10] = {1,2,3,33,43,1,0,3,44,5};
	//xzSort(arr,10);
	//xzSortS(arr,10);
	//mpSort(arr,10);
	mpSortS(arr,10);
	//quickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
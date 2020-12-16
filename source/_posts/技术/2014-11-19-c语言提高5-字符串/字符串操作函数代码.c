#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int  myStrLen(const char * str)
{
	int len=0;
	while (*str++)
		len++;
	return len;
}

char * myStrcpy(char * str1,const char * str2)
{
	char * t = str1;
	while (*str1++ = *str2++);
	return t;
}

int myStrcmpy(const char * str1, const char * str2)
{
	for (; *str1&&*str2; str1++, str2++)
	{
		if (*str1 == *str2)
			continue;
		else
			return *str1 - *str2;
	}
	return *str1 - *str2;
}

char * myStrcat(char * str1, const char * str2)
{
	char * t = str1;
	while (*str1)
		str1++;
	while (*str1++ = *str2++);
	return t;
}

//验证指定的字符是否在指定的字符串中
char * myStrchr(char * str,char item)
{
	while (*str)
	{
		if (*str == item)
			return str;
		str++;
	}
	return NULL;
}

//strchr ：查找单个字符是否存在指定的字符串中
int main1()
{
	char str[] = "china!"; 
	//char * newStr = myStrchr(str,'!');
	char * newStr = strchr(str,'c');
	if (newStr == NULL)
		printf("find none");
	else
		printf("find");
	return 0;
}

char * myStrstr_1(const char * str1, const char * str2)
{
	//首先求出短字符长度
	char * temp = str2;
	int len = 0;
	while (*str2)
	{
		str2++;
		len++;
	} 
	while (*str1)
	{
		if (0 == strncmp(str1, temp, len))
			return str1;
		*str1++;
	}
	return NULL;
}

char * myStrstr_2(const char * str1, const char * str2)
{
	//首先求出短字符长度
	char * temp = str2;
	int len = 0;
	while (*temp)
	{
		temp++;
		len++;
	}
	while (*str1)
	{
		for (int i = 0; *(str1 + i) == *(str2 + i); i++) //如果相等则进行比较  
		{
			if (*(str2 + i + 1) == '\0')
				return str1;
		} 
		str1++;
	}
	return NULL;
}

char * myStrstr(const char * str1, const char * str2)
{
	//首先求出短字符长度
	char * temp = str2;
	int len = 0;
	while (*temp)
	{
		temp++;
		len++;
	}
	//直接获取str1的首个和str2首个元素相等的元素
	for (; NULL != (str1 = strchr(str1, *str2)); str1++)
	{
		if (strncmp(str1, str2, len) == 0)
			return  str1;
	}
   	return NULL;
}

//strstr：查找一串字符是否在指定字符串中
int main2()
{
	char str1[] = "abcd123456efg";
	char str2[] = "1234"; 
	//char * newStr = strstr(str1, str2);
	char * newStr = myStrstr(str1,str2);
	if (newStr == NULL)
		printf("find none");
	else
		printf("find");
	return 0;
}

//strctok : 根据指定值来切割字符
int main()
{
	char buff[] = "34567%0dhbdjdb1hw1%0dhinpwq%0dsdjwid";
	char * temp = strtok(buff, "%0d");
	while (temp)
	{
		printf("%s\n",temp);
		temp=strtok(NULL, "%0d");//strtok  如果查找的字符串不存在，表示
	}
	return 0;
}
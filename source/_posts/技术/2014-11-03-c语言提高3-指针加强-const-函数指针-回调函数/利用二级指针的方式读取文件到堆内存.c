#define  _CRT_SECURE_NO_WARNINGS  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define fileName "file.txt"

void readFile(char *** p)
{ 
	FILE * fp = fopen(fileName,"r+");
	int fileRow = 0;
	char buff[1024];
	while (fgets(buff,sizeof(buff),fp))//fgets 判断是否结束是判断是否为NULL
	{
		fileRow++;
	} 

	//初始化文件指针
	rewind(fp);  
    *p= (char *)malloc(sizeof(char*)*(fileRow+1)); 
	char **  q =*p;
	while (fgets(buff, 1024, fp))
	{
		int n = strlen(buff);
		*q = (char*)malloc(n + 1);
		strcpy(*q, buff);
		q++;
	}
	*q = NULL;
	fclose(fp);
}

int main()
{
	char ** p = NULL;
	readFile(&p);
	while (*p)
	{
		printf("%s",*p++);
	}
	return 0;
}
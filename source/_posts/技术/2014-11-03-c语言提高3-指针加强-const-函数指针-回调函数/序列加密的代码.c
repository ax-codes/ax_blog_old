#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>


#if 0

按3列解析，解析成了5行

char * src = "china is great"

chi
na*
is*
gre
at*

char * sec = cnigahasrti**e*
按5列解析，解析成了3行

cniga
hasrt
i**e*

char *ensec = china is great




#endif

#if 0
char *p = "i love xxx";  //data ro   stack    8   2

i love x
xx^^^^^^0

2    8

ix xl^o^v^e^ ^x ^ 0

ix
x
l^
o^
v^
e^
^
x^

i love xxx00



#endif



char * encode(char * buf, int line)
{
	int len = strlen(buf);
	int  newLen = len;
	if (len%line != 0)
		newLen = len + line - len%line;

	char * tmp = malloc(newLen + 1);
	memset(tmp, 0, newLen);

	char * sec = malloc(newLen + 1);
	char *ps = sec;

	strcpy(tmp, buf);

	for (int i = len; i<newLen; i++)
	{
		tmp[i] = '^';
	}

	char(*p)[8] = tmp;

	for (int x = 0; x<line; x++)
	{
		for (int y = 0; y<newLen / line; y++)

			*ps++ = p[y][x];
	}
	free(tmp);
	*ps = '\0';

	return sec;
}

char * decode(char * sec, int line)
{
	int len = strlen(sec);
	char * t = malloc(len + 1);
	strcpy(t, sec);
	char * nt = malloc(len + 1);
	char *pnt = nt;
	char(*p)[2] = t;
	for (int x = 0; x<line; x++)
	{
		for (int y = 0; y<len / line; y++)
			*pnt++ = p[y][x];
	}
	*pnt = '\0';
	while (*(--pnt) == '^');
	*(++pnt) = '\0';
	free(t);
	return nt;
}

int main(void)
{
	char * buf = "i love xxx";

	char * sec = encode(buf, 8);
	printf("%s\n", sec);
	char * desec = decode(sec, 2);
	printf("%s\n", desec);


	free(sec);
	free(desec);


	return 0;
}


























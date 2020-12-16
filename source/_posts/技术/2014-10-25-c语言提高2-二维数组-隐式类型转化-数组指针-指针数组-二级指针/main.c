#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[]="\0373xei";//037算一个字节  后面的依次每个字符算一个字节
    //char str1[]="\0383xei";//03算一个字节 后面的依次每个字符算一个字节
    //char str2[]="\x2aet76543";//x2ae 算一个字节  后面的依次每个字符算一个字节
    char str2[]="\x3456aeccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";//这里只有一个字节因为全部都是十六进制的数据
	printf("%d\n",strlen(str1));
    printf("%d\n",strlen(str2));
    return 0;
}


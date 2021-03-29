#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char arr[]="abc";
    char arr2[]={'a','b','c','\0'};
    printf("内容:%s\n",arr);
    printf("内容:%s\n",arr2);
    printf("长度:%d\n",strlen(arr));
    printf("长度:%d\n",strlen(arr2));
    printf("大小:%d\n",sizeof arr);
    printf("大小:%d\n",sizeof arr2);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char arr[]="abc";
    char arr2[]={'a','b','c','\0'};
    printf("����:%s\n",arr);
    printf("����:%s\n",arr2);
    printf("����:%d\n",strlen(arr));
    printf("����:%d\n",strlen(arr2));
    printf("��С:%d\n",sizeof arr);
    printf("��С:%d\n",sizeof arr2);
    return 0;
}

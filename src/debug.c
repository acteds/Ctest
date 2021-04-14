#include<stdio.h>
#include<assert.h>
char * user_strcpy(char *p,const char *q){
    char *o = p;
    assert(p != NULL);
    assert(q != NULL);
    while (*q!='\0')
    {
        *p++ = *q++;
    }
    *p = '\0';
    return o;
}
int user_strlen(const char *p){
    assert(p != NULL);
    int count = 0;
    while (*p!='\0')
    {
        count++;
        p++;
    }
    return count;
}
int main(int argc, char const *argv[])
{
/*     int i = 0;//高地址
    int arr[3] = {1, 2, 3};
    for (; i <= 3;i++)
    {
        printf("hehe\n");
        //越界访问,arr[3],可能访问了i的地址
        arr[i] = 0;
    } */
    char a[] = "123456789";
    char b[] = "bit";
    user_strcpy(a, b);
    printf("%s\n", a);
    user_strcpy(a, &a[4]);
    printf("%s\n", a);
    printf("%d\n", user_strlen(a));
    return 0;
}

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<float.h>
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
/*     int i = 0;//�ߵ�ַ
    int arr[3] = {1, 2, 3};
    for (; i <= 3;i++)
    {
        printf("hehe\n");
        //Խ�����,arr[3],���ܷ�����i�ĵ�ַ
        arr[i] = 0;
    } */
    char a[] = "123456789";
    char b[] = "bit";
    user_strcpy(a, b);
    printf("%s\n", a);
    user_strcpy(a, &a[4]);
    printf("%s\n", a);
    printf("%d\n", user_strlen(a));
    {
        int a = 20;
        char *p = (char *)&a;
        printf("%s",*p?"С��\n":"���\n");
    }
    {
        char a = -1;
        signed char b = -1;
        unsigned char c = -1;
        //10000001,11111110,11111111,������������:
        printf("%d %d %d\n", a, b, c);
        char a1 = -128, a2 = 128;
        printf("%d %d\n", a1, a2);
        //10010100 -20ԭ��
        //11101100 -20����
        //00001010 10����
        //11110110 �Ͳ���
        //11110101 �ͷ���
        //10001010 ��ԭ��
        int i = -20;
        unsigned int j = 10;
        printf("%d\n", i + j);
    }
    {
        // ��ѭ��,�޷��Ų���С��0
        unsigned int i;
        // for (i = 9; i >=0; i--)
        // {
        //     printf("%u\n", i);
        // }
        //11111111
        //11111111
        char a[1000];
        for ( i = 0; i < 1000; i++)
        {
            a[i] = -1 - i;
        }
        printf("%d\n", strlen(a));
    }
    {
        int n = 9;
        float *p = (float *)&n;
        printf("%d %f \n", n, *p);
        *p = 9.0;
        printf("%d %f\n", n, *p);
    }
    return 0;
}

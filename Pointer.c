#include<stdio.h>
#include<malloc.h>

int main(int argc, char const *argv[])
{
    printf("%I64d\n", sizeof(char *));
    //在内存中是反着存的,因此15行打印11223300
    int a = 0x11223344;
    int *pa = &a;
    short *pb =(short *)&a;
    char *pc = (char *)&a;
    printf("%p %x\n", pa,*pa);
    printf("%p %x\n", pb,*pb);
    printf("%p %x\n", pc,*pc);
    *pc = 0;
    printf("%x\n", a);
    *pb = 0;
    printf("%x\n", a);
    *pa = 0;
    //步长
    printf("%x\n", a);
    printf("%p\n", &a);
    printf("%p\n", ++pa);
    printf("%p\n", ++pb);
    printf("%p\n", ++pc);
    {
        int arr[10] = {0};
        char *p = (char *)arr;
        int i = 0;
        for (i = 0; i < 10;i++){
            *(p + i) = 1;
        }
    }
    //野指针测试
    {
        //未初始化,就使用
        int *p;
        // *p = 1;
        printf("%p\n",p);
        //非法访问,越界
        int a[10] = {0};
        p = a;
        int i;
        for (i = 0; i < 15; i++)
        {
            *p = i;
            p++;
        }
        //局部变量地址
        int *tryPointer();
        p=tryPointer();
        // *p = 1;
        printf("%p", p=NULL);
    }

    {
        //指针加整数
        printf("\n");
        float a[5], *p = a;
        while (p<&a[5])
        {
            *p++ = 1;
            printf("%f\n", *(p-1));
        }
        //指针减指针,返回中间元素个数5.
        printf("%I64d\n", &a[5] - &a[0]);
        //字符串长度
        int user_strlen(char *s);
        int n = user_strlen("test string");
        printf("%d\n", n);
    }
    {//指针访问数组
        int arr[10] = {1,2,3,4,5,6,7,8,9,10};
        int *p = arr,i;
        for ( i = 0; i < 10; i++)
        {
            printf("%d ", *(p + i));
        }
        printf("\n");
    }
    //二级指针
    {
        int a = 10,*p=&a,**pp=&p;
        printf("%p %p %p\n", &a,p, *pp);
        printf("%d %d %d\n", a,*p, **pp);
    }
    //指针数组
    {
        int a = 10, b = 20, c = 30;
        int *p[3] = {&a, &b, &c};
        printf("%d %d %d\n", *p[0], *(p[1]), *(p[2]));
        printf("%d %d %d\n", **(p+0), **(p+1), **(p+2));
    }
    int count_2bit_1(int n);
    printf("%d\n", count_2bit_1(-1));
    {
        struct Stu
        {
            char name[20];
            short age;
            char tele[12];
            char sex[5];
        }s1,s2,s3;
        typedef struct lnk
        {
            int data;
            struct lnk *next;
        }S;
        S *s = malloc(sizeof(S));
        s->data = 100;
        s->next = malloc(sizeof(S));
        s->next->data = 200;
        printf("%d %d", s->data, s->next->data);
    }
    return 0;
}
/**
 * @brief  野指针测试
 * @note
 * @retval
 */
int * tryPointer()
{
    int a = 10;
    return &a;
}
/**
 * @brief  获取字符串长度
 * @note   指针相减实现
 * @param  s: 字符串
 * @retval 字符长度
 */
int user_strlen(char * s){
    char *p = s;
    while (*p!='\0')
    {
        p++;
    }
    return p - s;
}
/**
 * @brief  计算二进制位有多少个1
 * @note   
 * @param  n: 
 * @retval 
 */
int count_2bit_1(int n){
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

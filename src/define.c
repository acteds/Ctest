#include <stdio.h>
int main(int argc, char const *argv[])
{
    //todo 预定义符号
    printf("%s \n", __FILE__);     //todo 文件名称
    printf("%d \n", __LINE__);     //todo 代码行号
    printf("%s \n", __DATE__);     //todo 日期
    printf("%s \n", __TIME__);     //todo 时间
    printf("%s \n", __FUNCTION__); //todo 函数名称
    printf("%d \n", __STDC__);     //todo 是否遵循C标准
    //todo 自定义标识符
#define N 3
#define AA(X) ((X) * (X))
    printf("%d ", AA(10));
    //todo 常量字符串内不会被替换
    printf("N %d\n", N);
    //todo 没有问题的代码 输出hello word
    printf("hello "
           "word\n");
#define PRINT(X) printf("当前变量名称:" #X ",当前变量值为:%d\n", X)
    int a = 3, b = 40;
    PRINT(a);
    PRINT(b);
    //## 连接
    int ab = 10;
#define CAT(X1, X2) X1##X2
    PRINT(CAT(a, b)); //因为PRINT在外层则先执行PRINT
    printf("%d\n", CAT(a, b));
#define S(X) #X
    printf(S(CAT(a, b)));

    {
//todo 函数做不到的事
#define MALLOC(num, type) (type *)malloc(num * sizeof(type))
        int *p = MALLOC(10, int);
    }
    {
// #define DEBUG
#ifdef DEBUG
        printf("%d", 10);
#endif

#ifdef DEBUG
        printf("%d", 1);
#elif DEBUG2
        printf("%d", 2);
#else
        printf("%d\n", 3);
#endif

//等价 #ifdef DEBUG
#if defined(DEBUG)
        printf("%s", "DEBUG");
#endif

#ifndef DEBUG
        printf("没定义DEBUG\n");
#endif
//等价 #ifndef DEBUG
#if !defined(DEBUG)
        printf("没定义DEBUG\n");
#endif

#include <stddef.h>
        struct S
        {
            char c1; //0 1
            int a;   //4-7 4
            char c2; //8 1
        };           //9b 对齐后12b
        printf("%d\n", offsetof(struct S, a));
#define OFFSETOF(s, n) (int)&((s *)0)->n
        printf("%d\n", OFFSETOF(struct S, a));
    }

    return 0;
}
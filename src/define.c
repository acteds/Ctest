#include <stdio.h>
int main(int argc, char const *argv[])
{
    //todo Ԥ�������
    printf("%s \n", __FILE__);     //todo �ļ�����
    printf("%d \n", __LINE__);     //todo �����к�
    printf("%s \n", __DATE__);     //todo ����
    printf("%s \n", __TIME__);     //todo ʱ��
    printf("%s \n", __FUNCTION__); //todo ��������
    printf("%d \n", __STDC__);     //todo �Ƿ���ѭC��׼
    //todo �Զ����ʶ��
#define N 3
#define AA(X) ((X) * (X))
    printf("%d ", AA(10));
    //todo �����ַ����ڲ��ᱻ�滻
    printf("N %d\n", N);
    //todo û������Ĵ��� ���hello word
    printf("hello "
           "word\n");
#define PRINT(X) printf("��ǰ��������:" #X ",��ǰ����ֵΪ:%d\n", X)
    int a = 3, b = 40;
    PRINT(a);
    PRINT(b);
    //## ����
    int ab = 10;
#define CAT(X1, X2) X1##X2
    PRINT(CAT(a, b)); //��ΪPRINT���������ִ��PRINT
    printf("%d\n", CAT(a, b));
#define S(X) #X
    printf(S(CAT(a, b)));

    {
//todo ��������������
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

//�ȼ� #ifdef DEBUG
#if defined(DEBUG)
        printf("%s", "DEBUG");
#endif

#ifndef DEBUG
        printf("û����DEBUG\n");
#endif
//�ȼ� #ifndef DEBUG
#if !defined(DEBUG)
        printf("û����DEBUG\n");
#endif

#include <stddef.h>
        struct S
        {
            char c1; //0 1
            int a;   //4-7 4
            char c2; //8 1
        };           //9b �����12b
        printf("%d\n", offsetof(struct S, a));
#define OFFSETOF(s, n) (int)&((s *)0)->n
        printf("%d\n", OFFSETOF(struct S, a));
    }

    return 0;
}
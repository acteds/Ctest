#include<stdio.h>
#include<stddef.h>
struct student
{
    char name[20];//����
    char tele[12];//�绰
    char sex[10];//�Ա�
    int age;//����
}s1;
//����
struct Node
{
    int data;
    struct Node *next;
};
//�ṹ���ڴ����
struct S1
{
    char c1;//1�ֽ�
    int a;//4�ֽ� ->�����3�ֽ�,�ڴ����
    char c2;//1�ֽ�
};//9�ֽ�,��������Ϊ4,�����12�ֽ�
struct S2
{
    char c1;//1�ֽ�
    char c2;//1�ֽ�
    int a;//������Ϊ4,�˷�ǰ2�ֽ�,4�ֽ�
};//1+1+2+4=8�ֽ�,��������Ϊ4,�����Ϊ8�ֽ�
struct S3
{
    double d;//8�ֽ�
    char c;//1�ֽ�
    int i;//4�ֽ�,�˷�ǰ3�ֽ�
};//8+1+3+4=16�ֽ�,��������Ϊ8,�����Ϊ16�ֽ�
//����Ĭ�϶�����Ϊ4
#pragma pack(4)
struct S4
{
    char c1;//1�ֽ�
    //����Ĭ�϶�������,S3������������Ĭ�϶�����
    //,���ȡĬ�϶�����4,ǰ���˷�3�ֽ�,
    struct S3 s3;//�ýṹ����������Ϊ8,ǰ���˷�7�ֽ�,16�ֽ�
    double k;//8�ֽ�
};//1+7+16+8=32,��������Ϊ8,�����Ϊ32�ֽ�.
//ȡ������Ĭ�϶�����
#pragma pack()
int main(int argc, char const *argv[])
{
    //�ṹ���ڴ����,12 8
    printf("%I64d %I64d\n", sizeof(struct S1), sizeof(struct S2));
    //Ƕ�׽ṹ�����,16 28
    printf("%I64d %I64d\n", sizeof(struct S3), sizeof(struct S4));
    //offsetof,��,����ṹ���ڳ�Ա��ƫ����.
    //����:�ṹ������,�ṹ���Ա������.
    printf("%I64d ", offsetof(struct S4, c1));//0
    printf("%I64d ", offsetof(struct S4, s3));//4
    printf("%I64d \n", offsetof(struct S4, k));//20
    {
        //λ��,2����λ.
        struct A
        {
            int a : 2;//2bit
            int b : 5;//5bit
            int c : 10;//10bit
            //����ʹ��ʱ������32bit,ʣ��15bit
            //��������Ҫ30bit,�����������32bit
            int d : 30;//30bit,
        };//һ��64bit,8�ֽ�
        printf("%I64d\n", sizeof(struct A));
    }
    {
        enum sex
        {
            RED = 0,
            GREEN = 0,
            BLUE=0
        };
        enum sex s = (enum sex)0;
        printf("%d %d %d\n", RED, GREEN, BLUE);
        printf("%d %I64d\n", s,sizeof(enum sex));
    }
    {
        //������,������
        union un
        {
            char c;
            int i;
        }q;
        printf("%p %p\n",&q.c,&q.i);
        q.i = 0x11223344;
        printf("%x %x\n", q.c, q.i);
        if (q.c==0x44)
        {
            printf("С��\n");
        }else if(q.c==0x11){
            printf("���\n");
        }
        union arc
        {
            int a;
            char arr[5];//��������.
        };
        printf("%I64d\n", sizeof(union un));//4
        printf("%I64d\n", sizeof(union arc));//8
    }

    return 0;
}

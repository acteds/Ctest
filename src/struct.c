#include<stdio.h>
#include<stddef.h>
struct student
{
    char name[20];//名字
    char tele[12];//电话
    char sex[10];//性别
    int age;//年龄
}s1;
//链表
struct Node
{
    int data;
    struct Node *next;
};
//结构体内存对齐
struct S1
{
    char c1;//1字节
    int a;//4字节 ->上面空3字节,内存对齐
    char c2;//1字节
};//9字节,最大对齐数为4,对齐后12字节
struct S2
{
    char c1;//1字节
    char c2;//1字节
    int a;//对齐数为4,浪费前2字节,4字节
};//1+1+2+4=8字节,最大对齐数为4,对齐后为8字节
struct S3
{
    double d;//8字节
    char c;//1字节
    int i;//4字节,浪费前3字节
};//8+1+3+4=16字节,最大对齐数为8,对齐后为16字节
//设置默认对齐数为4
#pragma pack(4)
struct S4
{
    char c1;//1字节
    //设置默认对齐数后,S3最大对齐数大于默认对齐数
    //,因此取默认对齐数4,前面浪费3字节,
    struct S3 s3;//该结构体最大对齐数为8,前面浪费7字节,16字节
    double k;//8字节
};//1+7+16+8=32,最大对齐数为8,对齐后为32字节.
//取消设置默认对齐数
#pragma pack()
int main(int argc, char const *argv[])
{
    //结构体内存对齐,12 8
    printf("%I64d %I64d\n", sizeof(struct S1), sizeof(struct S2));
    //嵌套结构体对齐,16 28
    printf("%I64d %I64d\n", sizeof(struct S3), sizeof(struct S4));
    //offsetof,宏,计算结构体内成员的偏移量.
    //参数:结构体类型,结构体成员变量名.
    printf("%I64d ", offsetof(struct S4, c1));//0
    printf("%I64d ", offsetof(struct S4, s3));//4
    printf("%I64d \n", offsetof(struct S4, k));//20
    {
        //位段,2进制位.
        struct A
        {
            int a : 2;//2bit
            int b : 5;//5bit
            int c : 10;//10bit
            //上面使用时申请了32bit,剩下15bit
            //而下面需要30bit,因此重新申请32bit
            int d : 30;//30bit,
        };//一共64bit,8字节
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
        //联合体,共用体
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
            printf("小端\n");
        }else if(q.c==0x11){
            printf("大端\n");
        }
        union arc
        {
            int a;
            char arr[5];//最大对齐数.
        };
        printf("%I64d\n", sizeof(union un));//4
        printf("%I64d\n", sizeof(union arc));//8
    }

    return 0;
}

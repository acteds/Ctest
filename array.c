#include <stdio.h>
/*********************************
* 方法1: 第一维的长度可以不指定
*        但必须指定第二维的长度
*********************************/
void print_a(int a[][5], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

/*****************************************
* 方法2: 指向一个有5个元素一维数组的指针
*****************************************/
void print_b(int (*a)[5], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

/***********************************
* 方法3: 利用数组是顺序存储的特性,
*       通过降维来访问原数组!
***********************************/
void print_c(int *a, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", *(a + i * m + j));
        printf("\n");
    }
}
int main(void)
{
    int a[5][5] = {{1, 2}, {3, 4, 5}, {6}, {7}, {0, 8}};

    printf("\n方法1:\n");
    print_a(a, 5, 5);

    printf("\n方法2:\n");
    print_b(a, 5, 5);

    printf("\n方法3:\n");
    print_c(&a[0][0], 5, 5);

    //    getch();
    return 0;
}

#include <stdio.h>

void print_a(int a[][5], int n, int m);
void print_b(int (*a)[5], int n, int m);
void print_c(int *a, int n, int m);
void user_bubble(int *a, int n);
int main(int argc, char const *argv[])
{
    int a[5][5] = {{1, 2}, {3, 4, 5}, {6}, {7}, {0, 8}};

    printf("\n方法1:\n");
    print_a(a, 5, 5);

    printf("\n方法2:\n");
    print_b(a, 5, 5);

    printf("\n方法3:\n");
    print_c(&a[0][0], 5, 5);

    int bubble[10] = {10, 6, 8, 4, 7, 2, 1, 9, 3, 5};
    user_bubble(bubble, 10);
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", bubble[i]);
    }

    return 0;
}
/**
 * @brief  冒泡
 * @note
 * @param  *a: 数组
 * @param  n: 数组长度
 * @retval None
 */
void user_bubble(int *a,int n){
    int i, j,temp,flag;
    for (i = 0; i < n-1; i++)
    {
        //初始化标志变量,若该轮没有产生交换,则视为数组有序.
        flag = 1;
        //第一次将最大值放到n-1,第i次放到n-i-1的位置
        for ( j = 0; j < n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 0;
            }
        }
        if (flag==1)
        {
            printf("排序提前完成,共执行%d轮\n", i + 1);
            break;
        }
    }
};

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
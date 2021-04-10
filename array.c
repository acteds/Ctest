#include <stdio.h>

void print_a(int a[][5], int n, int m);
void print_b(int (*a)[5], int n, int m);
void print_c(int *a, int n, int m);
void user_bubble(int *a, int n);
int main(int argc, char const *argv[])
{
    int a[5][5] = {{1, 2}, {3, 4, 5}, {6}, {7}, {0, 8}};

    printf("\n����1:\n");
    print_a(a, 5, 5);

    printf("\n����2:\n");
    print_b(a, 5, 5);

    printf("\n����3:\n");
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
 * @brief  ð��
 * @note
 * @param  *a: ����
 * @param  n: ���鳤��
 * @retval None
 */
void user_bubble(int *a,int n){
    int i, j,temp,flag;
    for (i = 0; i < n-1; i++)
    {
        //��ʼ����־����,������û�в�������,����Ϊ��������.
        flag = 1;
        //��һ�ν����ֵ�ŵ�n-1,��i�ηŵ�n-i-1��λ��
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
            printf("������ǰ���,��ִ��%d��\n", i + 1);
            break;
        }
    }
};

/*********************************
* ����1: ��һά�ĳ��ȿ��Բ�ָ��
*        ������ָ���ڶ�ά�ĳ���
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
* ����2: ָ��һ����5��Ԫ��һά�����ָ��
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
* ����3: ����������˳��洢������,
*       ͨ����ά������ԭ����!
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
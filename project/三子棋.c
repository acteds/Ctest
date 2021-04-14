#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 3
void start();
int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    do
    {
        int flag = -1;
        printf("1.��ʼ��Ϸ,0,������Ϸ\n");
        scanf("%d", &flag);
        if (flag == 1)
        {
            start();
        }
        else if (flag == 0)
        {
            break;
        }
        else
        {
            printf("�����������������!\n");
        }
    } while (1);

    return 0;
}
void init(char a[][N], int n, int m);
void out(char a[][N], int n, int m);
void playercheck(char a[][N], int n, int m);
void computercheck(char a[][N], int n, int m);
int checkWin(char a[][N], int n, int m, int x, int y);
//ִ�п��Ʒ�
int flag = 0;
//����������
int count = 0;
void start()
{
    count = 0;
    flag = 0;
    printf("������\n");
    char arr[N][N] = {0};
    init(arr, N, N);
    while (1)
    {
        out(arr, N, N);
        playercheck(arr, N, N);
        if (flag) { break; }
        out(arr, N, N);
        computercheck(arr, N, N);
        if (flag) { break; }
    }
}
/**
 * @brief  ��ʼ��
 * @note
 * @param  a[][N]: ����
 * @param  n: ��
 * @param  m: ��
 * @retval None
 */
void init(char a[][N], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = ' ';
        }
    }
}
/**
 * @brief  �������Ļ
 * @note
 * @param  a[][N]: ����
 * @param  n: ��
 * @param  m: ��
 * @retval None
 */
void out(char a[][N], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" %c ", a[i][j]);
            // todo ���һ������ӡ
            if (j + 1 != m)
            {
                printf("��");
            }
        }
        printf("\n");
        // todo ���һ������ӡ
        if (i + 1 == n)
        {
            break;
        }
        for (j = 0; j < m; j++)
        {
            printf("������");
            // todo ���һ������ӡ
            if (j + 1 != m)
            {
                printf("��");
            }
        }
        printf("\n");
    }
}
/**
 * @brief  �������
 * @note
 * @param  a[][N]: ����
 * @param  n: ��
 * @param  m: ��
 * @retval None
 */
void playercheck(char a[][N], int n, int m)
{
    int x, y;
    if (count==N*N)
    {
        out(a, N, N);
        printf("��������,ƽ��!");
        flag = 1;
        return;
    }
    while (1)
    {
        printf("������λ��xy ��(1 1):");
        scanf("%d%d", &x, &y);
        if (x <= n && x >= 1 && y <= m && y >= 1)
        {
            if (a[x - 1][y - 1] == ' ')
            {
                a[x - 1][y - 1] = 'X';
                count++;
                break;
            }
            else
            {
                out(a, N, N);
                printf("�Ѿ���������,����������!\n");
            }
        }
        else
        {
            out(a, N, N);
            printf("û�����λ��!\n");
        }
    }
    int t = checkWin(a, N, N, x - 1, y - 1);
    if (t)
    {
        out(a, N, N);
        printf("���Ӯ��\n");
        flag = 1;
        return;
    }
}
/**
 * @brief  ��������
 * @note
 * @param  a[][N]: ����
 * @param  n: ��
 * @param  m: ��
 * @retval None
 */
void computercheck(char a[][N], int n, int m)
{
    int x, y;
    if (count==N*N)
    {
        out(a, N, N);
        printf("��������,ƽ��!\n");
        flag=1;
        return;
    }
    while (1)
    {
        x = rand() % n + 1;
        y = rand() % m + 1;
        if (x <= n && x >= 1 && y <= m && y >= 1)
        {
            if (a[x - 1][y - 1] == ' ')
            {
                a[x - 1][y - 1] = 'O';
                count++;
                break;
            }
        }
    }
    printf("����:%d %d\n", x, y);
    int t=checkWin(a, N, N, x - 1, y - 1);
    if (t)
    {
        out(a, N, N);
        printf("����Ӯ��\n");
        flag = 1;
        return;
    }
}
/**
 * @brief  �����Ӯ
 * @note   ��N��ֵΪ��Ӯ��׼,��N=4,��Ҫ4������
 * @param  a[][N]: ����
 * @param  n: ��
 * @param  m: ��
 * @param  x: x
 * @param  y: y
 * @retval ����1��ʤ����0�����
 */
int checkWin(char a[][N], int n, int m, int x, int y)
{
    int i;
    char q = a[x][y];
    //�ж���
    for (i = 0; i < n; i++)
    {
        if (a[x][i] != q)
        {
            break;
        }
    }
    if (i == n)
    {
        return 1;
    }
    //�ж���
    for (i = 0; i < n; i++)
    {
        if (a[i][y] != q)
        {
            break;
        }
    }
    if (i == n)
    {
        return 1;
    }
    //�ж�б.
    //todo ��б
    if (x == y)
    {
        for (i = 0; i < n; i++)
        {
            if (a[i][i] != q)
            {
                break;
            }
        }
        if (i == n)
        {
            return 1;
        }
    }
    else if (x + y + 1 == N)
    { //todo ��б
        for (i = 0; i < n; i++)
        {
            if (a[i][n - i - 1] != q)
            {
                break;
            }
        }
        if (i == n)
        {
            return 1;
        }
    }
    return 0;
}

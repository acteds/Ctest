#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
//����
#define XY 10
//����
#define LEI (XY*XY/10)

/* vscode�����ʽ���������ڨ������һ���ո񼴿�cmd������������ */
//����ʶ��
#define BIAO "��"
#define N XY + 2
void start();

int main(int argc, char const *argv[])
{
    system("title ɨ��");
    srand((unsigned int)time(NULL));
    start();
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
void init(int a[][N], int n, int m);
void out(int a[][N], int n, int m);
void playercheck(int a[][N], int n, int m);
void calculateTheThunder(int a[][N], int x, int y);
void checkOver(int a[][N], int n, int m);
//ִ�п��Ʒ�
int flag = 0;
void start()
{
    flag = 0;
    printf("ɨ��\n");
    int arr[N][N] = {0};
    init(arr, N-1, N-1);
    while (1)
    {
        out(arr, N-1, N-1);
        playercheck(arr, N-2, N-2);
        checkOver(arr, N - 1, N - 1);
        if (flag)
        {
            break;
        }
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
void init(int a[][N], int n, int m)
{
    int i, j,count=0;
    //todo ��ʼ��
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i==0)
            {
                a[i][j] = j;
            }else if(j==0){
                a[i][j] = i;
            }else{
                //����Ĭ��ֵ
                a[i][j] = -10 ;
            }
        }
    }
    //todo ����
    int x = 0, y = 0;
    while (count<LEI)
    {
        x = rand() % XY + 1;
        y = rand() % XY + 1;
        //-9Ϊ�ױ�ʶ��
        if (a[x][y]!=-9)
        {
            a[x][y] = -9;
            count++;
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
void out(int a[][N], int n, int m)
{
    system("cls");
    int i, j;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] <0)
            {
                //todo �����Ϸ��������ʽ��
                if (a[i][j]==-9&&flag)
                {
                    printf(" X ");
                }else{
                    printf(" %2s", BIAO);
                }
            }
            else if (a[i][j] == 0)
            {
                printf("   ");
            }
            else if (a[i][j] > 0)
            {
                //todo ���Ϊ��ʽը��
                if (a[i][j] == 9&&flag&&i!=0&&j!=0)
                {
                    printf(" X ");
                }else{
                    printf(" %-2d", a[i][j]);
                }

            }
            printf("��");
        }
        printf("\n");
        // todo ���һ������ӡ
        if (i + 1 == n)
        {
            for (j = 0; j < m; j++)
            {
                printf("������");
                // todo ���һ����ӡ�������
                if (j + 1 != m)
                {
                    printf("��");
                }
                else
                {
                    printf("��");
                }
            }
        }else{
            for (j = 0; j < m; j++)
            {
                printf("������");
                // todo ���һ����ӡ�������
                if (j + 1 != m)
                {
                    printf("��");
                }
                else
                {
                    printf("��");
                }
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
void playercheck(int a[][N], int n, int m)
{
    int x, y;
    while (1)
    {
        printf("������λ��xy ��(1 1):");
        scanf("%d%d", &x, &y);
        if (x <= n && x >= 1 && y <= m && y >= 1)
        {
            if (a[x][y] <0)
            {
                calculateTheThunder(a, x, y);
                break;
            }
            else
            {
                out(a, N-1, N-1);
                printf("���λ���Ѿ��Ź���!\n");
            }
        }
        else
        {
            out(a, N-1, N-1);
            printf("û�����λ��!\n");
        }
    }
}
/**
 * @brief  ������Χ����
 * @note
 * @param  a[][N]:����
 * @param  x: x
 * @param  y: y
 * @retval
 */
void calculateTheThunder(int a[][N],int x,int y){
    int i, j,n=0;
    if (a[x][y]==-9)
    {
        a[x][y] = -a[x][y];
        return;
    }
    if (a[x][y] >= 0)
    {
        return;
    }
    for (i = x-1; i <= x+1; i++)
    {
        for (j = y-1; j <= y+1; j++)
        {
            if (a[i][j]==-9)
            {
                n++;
            }
        }
    }
    a[x][y] = n;
    //�����Χû����,��ݹ����
    if (n == 0)
    {
        for (i = x - 1; i <= x + 1; i++)
        {
            for (j = y - 1; j <= y + 1; j++)
            {
                if (i<=XY&&j<=XY&&i>=1&&j>=1)
                {
                    // printf("%d %d %d", i, j, a[i][j]);
                    calculateTheThunder(a, i, j);
                }
            }
        }
    }
}
/**
 * @brief  �����Ϸ����
 * @note   
 * @param  a[][N]: ����
 * @param  n: ��
 * @param  m: ��
 * @retval 
 */
void checkOver(int a[][N], int n, int m)
{
    int i, j,count=0;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            //todo ������
            if (a[i][j] == 9)
            {
                flag = 1;
                out(a, N - 1, N - 1);
                printf("��ȵ�����,��Ϸ����\n");
            }
            //todo δ������λ��
            if (a[i][j]<0)
            {
                count++;
            }
        }
    }
    if (count==LEI)
    {
        flag = 2;
        out(a, N - 1, N - 1);
        printf("��ϲ��,�����׶����ҵ���\n");
    }
}
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
        printf("1.开始游戏,0,结束游戏\n");
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
            printf("输入错误请重新输入!\n");
        }
    } while (1);

    return 0;
}
void init(char a[][N], int n, int m);
void out(char a[][N], int n, int m);
void playercheck(char a[][N], int n, int m);
void computercheck(char a[][N], int n, int m);
int checkWin(char a[][N], int n, int m, int x, int y);
//执行控制阀
int flag = 0;
//棋盘棋子数
int count = 0;
void start()
{
    count = 0;
    flag = 0;
    printf("三子棋\n");
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
 * @brief  初始化
 * @note
 * @param  a[][N]: 数组
 * @param  n: 行
 * @param  m: 列
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
 * @brief  输出到屏幕
 * @note
 * @param  a[][N]: 数组
 * @param  n: 行
 * @param  m: 列
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
            // todo 最后一个不打印
            if (j + 1 != m)
            {
                printf("┃");
            }
        }
        printf("\n");
        // todo 最后一个不打印
        if (i + 1 == n)
        {
            break;
        }
        for (j = 0; j < m; j++)
        {
            printf("━━━");
            // todo 最后一个不打印
            if (j + 1 != m)
            {
                printf("╋");
            }
        }
        printf("\n");
    }
}
/**
 * @brief  玩家下棋
 * @note
 * @param  a[][N]: 数组
 * @param  n: 行
 * @param  m: 列
 * @retval None
 */
void playercheck(char a[][N], int n, int m)
{
    int x, y;
    if (count==N*N)
    {
        out(a, N, N);
        printf("棋盘满了,平局!");
        flag = 1;
        return;
    }
    while (1)
    {
        printf("请输入位置xy 例(1 1):");
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
                printf("已经有棋子了,请重新输入!\n");
            }
        }
        else
        {
            out(a, N, N);
            printf("没有这个位置!\n");
        }
    }
    int t = checkWin(a, N, N, x - 1, y - 1);
    if (t)
    {
        out(a, N, N);
        printf("玩家赢了\n");
        flag = 1;
        return;
    }
}
/**
 * @brief  电脑下棋
 * @note
 * @param  a[][N]: 数组
 * @param  n: 行
 * @param  m: 列
 * @retval None
 */
void computercheck(char a[][N], int n, int m)
{
    int x, y;
    if (count==N*N)
    {
        out(a, N, N);
        printf("棋盘满了,平局!\n");
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
    printf("电脑:%d %d\n", x, y);
    int t=checkWin(a, N, N, x - 1, y - 1);
    if (t)
    {
        out(a, N, N);
        printf("电脑赢了\n");
        flag = 1;
        return;
    }
}
/**
 * @brief  检测输赢
 * @note   以N的值为输赢标准,即N=4,则要4个相连
 * @param  a[][N]: 数组
 * @param  n: 行
 * @param  m: 列
 * @param  x: x
 * @param  y: y
 * @retval 返回1则胜返回0则继续
 */
int checkWin(char a[][N], int n, int m, int x, int y)
{
    int i;
    char q = a[x][y];
    //判断行
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
    //判断列
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
    //判断斜.
    //todo 左斜
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
    { //todo 右斜
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

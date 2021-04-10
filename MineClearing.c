#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
//长宽
#define XY 10
//雷数
#define LEI (XY*XY/10)

/* vscode输出格式若变形则在█后面加一个空格即可cmd运行是正常的 */
//暗标识符
#define BIAO "█"
#define N XY + 2
void start();

int main(int argc, char const *argv[])
{
    system("title 扫雷");
    srand((unsigned int)time(NULL));
    start();
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
void init(int a[][N], int n, int m);
void out(int a[][N], int n, int m);
void playercheck(int a[][N], int n, int m);
void calculateTheThunder(int a[][N], int x, int y);
void checkOver(int a[][N], int n, int m);
//执行控制阀
int flag = 0;
void start()
{
    flag = 0;
    printf("扫雷\n");
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
 * @brief  初始化
 * @note
 * @param  a[][N]: 数组
 * @param  n: 行
 * @param  m: 列
 * @retval None
 */
void init(int a[][N], int n, int m)
{
    int i, j,count=0;
    //todo 初始化
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
                //无雷默认值
                a[i][j] = -10 ;
            }
        }
    }
    //todo 埋雷
    int x = 0, y = 0;
    while (count<LEI)
    {
        x = rand() % XY + 1;
        y = rand() % XY + 1;
        //-9为雷标识符
        if (a[x][y]!=-9)
        {
            a[x][y] = -9;
            count++;
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
                //todo 如果游戏结束则显式雷
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
                //todo 如果为显式炸弹
                if (a[i][j] == 9&&flag&&i!=0&&j!=0)
                {
                    printf(" X ");
                }else{
                    printf(" %-2d", a[i][j]);
                }

            }
            printf("┃");
        }
        printf("\n");
        // todo 最后一个不打印
        if (i + 1 == n)
        {
            for (j = 0; j < m; j++)
            {
                printf("━━━");
                // todo 最后一个打印特殊符号
                if (j + 1 != m)
                {
                    printf("┻");
                }
                else
                {
                    printf("┛");
                }
            }
        }else{
            for (j = 0; j < m; j++)
            {
                printf("━━━");
                // todo 最后一个打印特殊符号
                if (j + 1 != m)
                {
                    printf("╋");
                }
                else
                {
                    printf("┫");
                }
            }
        }
        printf("\n");
    }
}
/**
 * @brief  玩家排雷
 * @note
 * @param  a[][N]: 数组
 * @param  n: 行
 * @param  m: 列
 * @retval None
 */
void playercheck(int a[][N], int n, int m)
{
    int x, y;
    while (1)
    {
        printf("请输入位置xy 例(1 1):");
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
                printf("这个位置已经排过了!\n");
            }
        }
        else
        {
            out(a, N-1, N-1);
            printf("没有这个位置!\n");
        }
    }
}
/**
 * @brief  计算周围雷数
 * @note
 * @param  a[][N]:雷区
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
    //如果周围没有雷,则递归调用
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
 * @brief  检测游戏结束
 * @note   
 * @param  a[][N]: 数组
 * @param  n: 行
 * @param  m: 列
 * @retval 
 */
void checkOver(int a[][N], int n, int m)
{
    int i, j,count=0;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            //todo 踩雷了
            if (a[i][j] == 9)
            {
                flag = 1;
                out(a, N - 1, N - 1);
                printf("你踩到雷了,游戏结束\n");
            }
            //todo 未被检查的位置
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
        printf("恭喜你,所有雷都被找到了\n");
    }
}
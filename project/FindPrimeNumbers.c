#include <math.h>
#include <stdio.h>
#include <time.h>
#define N 2000000
#define OUT 0
#define TYPE long
int primeNumber(TYPE a);
void startRun1();
void startRun2();
void startRun3();
void startRun4();
/* N 为计算 2~N范围内的素数
 * OUT 为是否将找到的素数输出到控制台
 * TYPE 为定义的类型,若溢出请调整
 * * * */
/**
 * @brief  全局素数计数
 * @retval None
 */
TYPE count = 0;

int main(int argc, char const *argv[])
{
    //定义两个结构体，来记录开始和结束时间
    struct timeval start;
    struct timeval end;
    //记录两个时间差
    unsigned long diff;
    //todo 方法1
    count = 0;
    //第一次获取时间，即表示开始记时
    mingw_gettimeofday(&start, NULL);
    //运行自己的程序
    startRun1();
    //第二次获取时间，即表示结束记时
    mingw_gettimeofday(&end, NULL);

    //计算时间差，并打印
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Ordinary Method:");
    printf("time:%10ldμs", diff);
    printf(",count:%ld\n", count);

    //todo 方法2
    count = 0;
    //第一次获取时间，即表示开始记时
    mingw_gettimeofday(&start, NULL);
    //运行自己的程序
    startRun2();
    //第二次获取时间，即表示结束记时
    mingw_gettimeofday(&end, NULL);

    //计算时间差，并打印
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Optimization Method:");
    printf("time:%10ldμs", diff);
    printf(",count:%ld\n", count);

    //todo 方法3
    count = 0;
    //第一次获取时间，即表示开始记时
    mingw_gettimeofday(&start, NULL);
    //运行自己的程序
    startRun3();
    //第二次获取时间，即表示结束记时
    mingw_gettimeofday(&end, NULL);

    //计算时间差，并打印
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Optimization Method:");
    printf("time:%10ldμs", diff);
    printf(",count:%ld\n", count);

    //todo 方法4
    count = 0;
    //第一次获取时间，即表示开始记时
    mingw_gettimeofday(&start, NULL);
    //运行自己的程序
    startRun4();
    //第二次获取时间，即表示结束记时
    mingw_gettimeofday(&end, NULL);

    //计算时间差，并打印
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Optimization Method:");
    printf("time:%10ldμs", diff);
    printf(",count:%ld\n", count);

    return 0;
}
/**
 * @brief  判断是否为素数,标准试除法
 * @note
 * @param  a: 大于1的整数
 * @retval 结果
 */
int primeNumber(TYPE a)
{
    // todo 不为2且能被2整除
    if (a % 2 == 0 && a != 2)
    {
        return 0;
    }
    TYPE i = 3;
    for (; i <= sqrt(a); i += 2)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
};
/**
 * @brief  标准试除法
 * @note
 * @retval None
 */
void startRun1()
{
    TYPE i;
    if (N >= 2)
    {
        count++;
        if (OUT)
        {
            printf("2 ");
        }
    }
    // todo 从三开始,并跳过2的倍数
    for (i = 3; i <= N; i += 2)
    {
        if (primeNumber(i))
        {
            count++;
            if (OUT)
            {
                printf("%ld ", i);
            }
        }
    }
}
//!需要声明为全局变量,局部变量是使用栈的.
TYPE a[N + 1] = {0};
/**
 * @brief  由标准试除法优化
 * @note   出于可读性,就不对内存优化了,即a无需存储对应的数字,只需一位表示是否为素数
 * @retval None
 */
void startRun2()
{
    TYPE i, j;
    //todo 初始化所有不被2整除的数
    for (i = 3; i <= N; i += 2)
    {
        a[i] = i;
    }
    // todo 从三开始,并跳过2的倍数
    for (i = 3; i <= N; i += 2)
    {
        // todo 当数被置0时即不为素数,跳过
        if (a[i] == 0)
        {
            continue;
        }
        if (primeNumber(a[i]))
        { // todo 当该数为素数时,将之的倍数全部置零
            for (j = 2 * a[i]; j <= N; j += a[i])
            {
                // todo 当数为0时即不为素数,跳过
                if (a[j] == 0)
                {
                    continue;
                }
                a[j] = 0;
            }
        }
        else
        {
            a[i] = 0;
        }
    }
    // todo 输出结果
    if (N >= 2)
    {
        count++;
        if (OUT)
        {
            printf("2 ");
        }
    }
    // todo 从三开始,并跳过2的倍数
    for (i = 3; i <= N; i += 2)
    { // todo 当数为0时即不为素数,跳过
        if (a[i] == 0)
        {
            continue;
        }
        count++;
        if (OUT)
        {
            printf("%ld ", a[i]);
        }
    }
}

//!需要声明为全局变量,局部变量是使用栈的.
TYPE a2[N + 1] = {0};
// todo 素数集合,应为N/lnN,误差为15%
TYPE list[N / 2 + 1] = {0};
/**
 * @brief  筛法
 * @note   未优化内存
 * @retval None
 */
void startRun3()
{
    TYPE i, j, listCount = 0;
    //todo 初始化所有不被2整除的数
    for (i = 3; i <= N; i += 2)
    {
        a2[i] = i;
    }
    // todo 从三开始,并跳过2的倍数
    for (i = 3; i <= N; i += 2)
    {
        // todo 遍历素数集合
        for (j = 0; j < listCount; j++)
        {
            // todo 当除数大于被除数开方时退出
            if (list[j] > sqrt(a2[i]))
            {
                break;
            }
            // todo 被整除时退出
            if (a2[i] % list[j] == 0)
            {
                break;
            }
        }
        // todo 若没有被整除则视为素数,加入素数集合
        if (j >= listCount || list[j] > sqrt(a2[i]))
        {
            list[listCount] = a2[i];
            // todo 集合内素数数量加1
            listCount++;
        }
    }
    // todo 输出结果
    if (N >= 2)
    {
        count++;
        if (OUT)
        {
            printf("2 ");
        }
    }
    for (i = 0; i < listCount; i++)
    {
        count++;
        if (OUT)
        {
            printf("%ld ", list[i]);
        }
    }
}

//!需要声明为全局变量,局部变量是使用栈的.
// todo 素数集合,应为N/lnN,误差为15%
TYPE list2[N / 2 + 1] = {0};
/**
 * @brief  筛法
 * @note   优化内存
 * @retval None
 */
void startRun4()
{
    TYPE i, j, listCount = 0;
    // todo 从三开始,并跳过2的倍数
    for (i = 3; i <= N; i += 2)
    {
        // todo 遍历素数集合
        for (j = 0; j < listCount; j++)
        {
            // todo 当除数大于被除数开方时退出
            if (list2[j] > sqrt(i))
            {
                break;
            }
            // todo 被整除时退出
            if (i % list2[j] == 0)
            {
                break;
            }
        }
        // todo 若没有被整除则视为素数,加入素数集合
        if (j >= listCount || list2[j] > sqrt(i))
        {
            list2[listCount] = i;
            // todo 集合内素数数量加1
            listCount++;
        }
    }
    // todo 输出结果
    if (N >= 2)
    {
        count++;
        if (OUT)
        {
            printf("2 ");
        }
    }
    for (i = 0; i < listCount; i++)
    {
        count++;
        if (OUT)
        {
            printf("%ld ", list2[i]);
        }
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int slen(char *a);
void output(int n);
int user_factorial(int n);
int main(int argc, char const *argv[])
{
    // todo 一个一个数字输出
    output(12345);

    char v2[20] = "str test test";
    // todo 数组长度
    printf("\n%d", slen(v2));

    // todo 阶乘
    printf("\n%d", user_factorial(8));
    return 0;
}

/**
 * @brief  递归阶乘
 * @note
 * @param  n: 阶乘
 * @retval
 */
int user_factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return factorial(n - 1) * n;
};
/**
 * @brief  通过递归求数组长度
 * @note   不创建临时变量
 * @param  *a: 指针
 * @retval 长度
 */
int slen(char *a)
{
    if (*a == '\0')
    {
        return 0;
    }
    a++;
    return slen(a) + 1;
}
/**
 * @brief  一个一个打印数字
 * @param  n: 数
 * @note
 * @retval
 */
void output(int n)
{
    if (n == 0)
    {
        return;
    }

    output(n / 10);
    printf("%d", n % 10);
}
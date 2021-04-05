#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    for (int i = 1; i < 10; i++)
    {
        //该操作只会跳过i==5之后的语句,然后执行i++;
        if (i == 5)
        {
            continue;
        }
        printf("%d", i);
    }
    printf("\n");
    int i = 0;
    while (i <= 10)
    {
        //该操作会使i++;语句无法执行,导致死循环
        if (i == 5)
        {
            continue;
        }
        printf("%d", i);
        i++;
    }
    return 0;
}

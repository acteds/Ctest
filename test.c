#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    for (int i = 1; i < 10; i++)
    {
        //�ò���ֻ������i==5֮������,Ȼ��ִ��i++;
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
        //�ò�����ʹi++;����޷�ִ��,������ѭ��
        if (i == 5)
        {
            continue;
        }
        printf("%d", i);
        i++;
    }
    return 0;
}

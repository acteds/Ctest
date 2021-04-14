#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void start();
int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    do
    {
        int flag = -1;
        printf("1.开始游戏,0,结束游戏\n");
        scanf("%d", &flag);
        if (flag==1)
        {
            start();
        }else if (flag==0)
        {
            break;
        }else{
            printf("输入错误请重新输入!\n");
        }
    } while (1);

    return 0;
}
void start(){
    // todo 生成随机数
    int n = rand()%100+1;
    int m = 0;
    printf("猜数字\n");
    while (1)
    {
        scanf("%d",&m);
        if (m == n)
        {
            printf("猜对了\n");
            break;
        }else if (m>n)
        {
            printf("猜大了");
        }else if (m<n)
        {
            printf("猜小了");
        }
    }
}
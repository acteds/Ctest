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
        printf("1.��ʼ��Ϸ,0,������Ϸ\n");
        scanf("%d", &flag);
        if (flag==1)
        {
            start();
        }else if (flag==0)
        {
            break;
        }else{
            printf("�����������������!\n");
        }
    } while (1);

    return 0;
}
void start(){
    // todo ���������
    int n = rand()%100+1;
    int m = 0;
    printf("������\n");
    while (1)
    {
        scanf("%d",&m);
        if (m == n)
        {
            printf("�¶���\n");
            break;
        }else if (m>n)
        {
            printf("�´���");
        }else if (m<n)
        {
            printf("��С��");
        }
    }
}
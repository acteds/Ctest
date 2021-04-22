#include<stdio.h>
#include<malloc.h>
typedef struct Address
{
    char name[20];
    int age;
    char sex[5];
    char tele[12];
    char addr[30];
    struct Address *next;
}P;
P* add(P *p){
    P *q = malloc(sizeof(P)),*p2=p;
    if (p2==NULL)
    {
        q->next = NULL;
        p2 = q;
    }else{
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = q;
    }

    printf("输入姓名:");
    scanf("%s", q->name);
    printf("输入年龄:");
    scanf("%d", &q->age);
    printf("输入性别:");
    scanf("%s", &q->sex);
    printf("输入电话:");
    scanf("%s", q->tele);
    printf("输入地址:");
    scanf("%s", q->addr);
    return p2;
}
void del(P *p){
    print(p);
}
void print(P *p)
{
    printf("  姓名  年龄 性别     电话              地址     \n");
    while (p!=NULL)
    {
        printf("%-8s%-6d%-6s%-14s %-14s\n", p->name, p->age,p->sex, p->tele, p->addr);
        p=p->next;
    }
}
int main(int argc, char const *argv[])
{
    int i = 0;
    P init={"张三",18,"男","1341243214","地址测试地址测试",NULL},*p = &init;
    do
    {
        printf("0.exit,1.add,2.del,3.print\n");
        scanf("%d", &i);
        switch (i)
        {
        case 0:
            break;
        case 1:
            p=add(p);
            break;
        case 2:
            del(p);
            break;
        case 3:
            print(p);
            break;
        default:
            break;
        }
    } while (i);

    return 0;
    }

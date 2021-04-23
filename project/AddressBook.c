#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Address
{
    char name[20];
    int age;
    char sex[5];
    char tele[12];
    char addr[30];
    struct Address *next;
} P;
void change(P *);
void out(P *);
P *add(P *);
P *del(P *);
int main(int argc, char const *argv[])
{
    int i = 0;
    P *p = malloc(sizeof(P));
    strcpy(p->name, "����");
    p->age = 18;
    strcpy(p->sex, "��");
    strcpy(p->tele, "1341243214");
    strcpy(p->addr, "��ַ���Ե�ַ����");
    p->next = NULL;
    do
    {
        printf("0.exit,1.add,2.del,3.out,4.chage\n");
        scanf("%d", &i);
        switch (i)
        {
        case 0:
            break;
        case 1:
            p = add(p);
            break;
        case 2:
            p = del(p);
            break;
        case 3:
            out(p);
            break;
        case 4:
            change(p);
            break;
        default:
            break;
        }
    } while (i);

    return 0;
}
void change(P *p)
{
    out(p);
    printf("������Ҫ�޸ĵ�����:");
    char a[20];
    scanf("%s", a);
    while (p)
    {
        if (strcmp(p->name, a) == 0)
        {
            printf("��������:");
            scanf("%s", p->name);
            printf("��������:");
            scanf("%d", &p->age);
            printf("�����Ա�:");
            scanf("%s", p->sex);
            printf("����绰:");
            scanf("%s", p->tele);
            printf("�����ַ:");
            scanf("%s", p->addr);
            return;
        }
        p = p->next;
    }
    printf("�������������");
}
void out(P *p)
{
    printf("  ����  ���� �Ա�     �绰              ��ַ     \n");
    while (p != NULL)
    {
        printf("%-8s%-6d%-6s%-14s %-14s\n", p->name, p->age, p->sex, p->tele, p->addr);
        p = p->next;
    }
}
P *add(P *p)
{
    P *q = malloc(sizeof(P)), *p2 = p;
    if (p2 == NULL)
    {
        q->next = NULL;
        p2 = q;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
        q->next = NULL;
    }

    printf("��������:");
    scanf("%s", q->name);
    printf("��������:");
    scanf("%d", &q->age);
    printf("�����Ա�:");
    scanf("%s", q->sex);
    printf("����绰:");
    scanf("%s", q->tele);
    printf("�����ַ:");
    scanf("%s", q->addr);
    return p2;
}
P *del(P *p)
{
    out(p);
    printf("������Ҫɾ��������:");
    char a[20];
    scanf("%s", a);
    P *q = p;
    P *const top = p;
    while (p)
    {
        if (strcmp(p->name, a) == 0)
        {
            if (p == q)
            {
                q = p->next;
                free(p);
                return q;
            }
            else
            {
                q->next = p->next;
                free(p);
                return top;
            }
        }
        q = p;
        p = p->next;
    }
    printf("û���������\n");
    return top;
}

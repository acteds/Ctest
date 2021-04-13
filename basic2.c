#include <stdio.h>
#include <limits.h>


int main(int argc, char const *argv[])
{
    //sizeof �ڴ��벻ִ��.
    {
        short s = 0;
        int a = 10;
        printf("%I64d\n", sizeof(s = a + 5));
        printf("%d\n", s);
    }

    //~ �Զ�����λ����:
    {
        int a = 11;
        a = a | (1 << 2);
        printf("%d\n", a);
        a = a & (~(1 << 2));
        printf("%d\n", a);
    }
    //&& ||
    {
        int i = 0, a = 1, b = 2, c = 3, d = 4;
        i = a++ || ++b || d++;
        printf("%d %d %d %d %d\n", a, b, c, d,i);
        i = 0, a = 1, b = 2, c = 3, d = 4;
        i = a++ && ++b && d++;
        printf("%d %d %d %d %d\n", a, b, c, d,i);
    }
    //�ṹ��,->������
    {
        struct Stu
        {
            char name[20];
            int age;
            char id[20];
        };
        struct Stu s1 = {"����", 20, "001"}, *p = &s1;
        printf("%s %d %s\n", s1.name, s1.age, s1.id);
        printf("%s %d %s\n", p->name, p->age, p->id);
        printf("%s %d %s\n", (*p).name, (*p).age, (*p).id);
    }
    //��������
    {
        char a = 3, b = 127, c = a + b;
        printf("%d", c);
    }
    {
        char a = 0xb6;
        short b = 0xb600;
        int c = 0xb6000000;
        if (a==0xb6)
        {
            printf("a");
        }
        if (b == 0xb600)
        {
            printf("b");
        }
        if (c == 0xb6000000)
        {
            printf("c");
        }
        printf("\n");
    }
    {
        char c = 1;
        printf("%u\n",sizeof(c));
        printf("%u\n",sizeof(+c));
        printf("%u\n",sizeof(!c));
    }
    // ���ȼ�
    {
        int c = 1;
        c=c + --c;//�޷�Ԥ���ֵ.
        printf("%d", c);
        int i = 10;
        //�޷�Ԥ���ֵ.
        i = i-- - --i * (i = -3) * i++ + ++i;
        printf("\n%d", i);
        //�޷�Ԥ���ֵ.
        i = 1;
        int a = (++i) + (++i) + (++i);
        printf("\n%d", a);
    }
    return 0;
}

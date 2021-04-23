#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(int argc, char const *argv[])
{
    //使用malloc向操作系统申请动态内存空间.
    int *p = (int *)malloc(10 * sizeof(int));
    //申请失败时malloc返回空指针NULL
    if (p == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        //todo 输出随机值.
        int i;
        for (i = 0; i < 10; i++)
        {
            printf("%d ", *(p + i));
        }
        printf("\n");
    }

    //当动态空间使用完毕后,可以使用free还回空间.
    free(p);
    p = NULL;
    {
        //使用calloc向内存申请10个sizeof(int)的元素并将每个字节初始化为0
        int *p = (int *)calloc(10, sizeof(int));
        int i;
        //全部为0
        for (i = 0; i < 10; i++)
        {
            printf("%d ", *(p + i));
        }
        printf("\n");
        //todo realloc(p,n) 修改空间大小
        //若之后的空间够用,则返回原地址,若不够用则在新位置开辟空间
        //并复制之前的值到新空间,返回新的地址,并释放旧的空间
        //追加空间.若开辟空间失败则返回NULL.
        //因此不要直接赋值给p,如果申请失败返回NULL,p之前的内存也找不到了
        int *q = realloc(p, 20 * sizeof(int));
        printf("%p %p\n", p, q);
        if (q != NULL)
        {
            p = q;
        }
        free(q);
        q = NULL;
    }
    {
        //todo 使用realloc完成malloc的功能
        int *p = (int *)realloc(NULL, 40);
        free(p);
        p = NULL;
    }
    {
        //todo 题目
        char *tips1(char *p);
        char *str = NULL;
        //传值调用,调用完毕后str没有改变.
        //修改后将得到的地址返回给str.
        str = tips1(str);
        //str==NULL ,出现解引用空指针
        strcpy(str, "hello world");
        //相当于printf("字符串");
        printf(str);
        printf("\n");
    }
    {
        char *tips2();
        //返回了栈空间地址,造成非法访问内存.
        char *str = tips2();
        printf(str);
    }
    {
        char *str = (char *)malloc(100);
        strcpy(str, "hello");
        //动态内存释放.不会改变str的指向
        free(str);
        if (str != NULL)
        {
            //非法访问
            strcpy(str, "world\n");
            printf(str);
        }
    }
    {
        //todo 柔性数组
        struct S
        {
            int n;
            int arr[0]; //柔性数组成员
            //或写成int arr[];
        };
        //柔性数组成员时不计算大小.
        printf("%d\n", sizeof(struct S));
        //柔性数组的创建应该使用malloc
        struct S *p = (struct S *)malloc(sizeof(struct S) + 5 * sizeof(int));
        p->n = 0xff;
        int i = 0;
        for (i = 0; i < 5; i++)
        {
            p->arr[i] = 0xaa;
        }
        //改变动态空间大小
        struct S *q = realloc(p, 44);
        if (q != NULL)
        {
            p = q;
        }
        for (i = 5; i < 10; i++)
        {
            p->arr[i] = 0xbb;
        }
        for (i = 0; i < 10; i++)
        {
            printf("%x ", p->arr[i]);
        }
        printf("\n");
        free(p);
        p = NULL;
    }
    return 0;
}
char *tips1(char *p)
{
    //内存泄露
    p = (char *)malloc(100);
    return p;
}
char *tips2()
{
    char p[] = "hello world";
    return p;
}
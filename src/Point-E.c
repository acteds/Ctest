#include <stdio.h>
int main(int argc, char const *argv[])
{
    char arr[] = "abcdef";
    char *p = arr;
    printf("%s\n", arr);
    printf("%s\n", p);
    //todo 指向字符串的指针,指针存放字符串首地址,
    //todo 该字符串为常量字符串,无法更改,可加const显示声明!.
    {
        const char *q = "test aaa";
        //*q = 'w';
        printf("%s\n", q);
    }
    {//todo 常量字符串.
        char arr1[] = "abc", arr2[] = "abc";
        char *p1 = "abc", *p2 = "abc";
        if (p1==p2)
        {
            printf("%p %p\n", p1, p2);
        }
        if (arr1!=arr2)
        {
            printf("%p %p\n", arr1, arr2);
        }
    }
    {//todo 数组指针,指向数组的指针
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *p = arr;//todo 普通指针
        printf("%p %p\n", p, p + 1);
        int(*q)[10] = &arr;//todo 数组指针
        printf("%p %p\n", q, q + 1);//一次跳过整个数组大小的地址.

        char *arr2[5];
        char *(*pa)[5] = &arr2;

        //适当的用法:二维数组以上时使用.
        int arr3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int(*p2)[3] = &arr3;
        int i = 0, j = 0;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d ", p2[i][j]);
                printf("%d ", (*(p2+i))[j]);
                printf("%d ", *(*(p2+i)+j));
            }
            printf("\n");
        }
    }
    {
        //todo 函数指针,add,&add都是指函数的地址.
        int add(int, int);
        printf("%p\n", add);
        printf("%p\n", &add);
        //todo 若不加括号则会变成返回值为指针的函数声明.
        int (*p)(int, int) = add;
        printf("%p\n", *p);
        //todo 函数指针调用时,可以写*也可以不写
        printf("%d\n", (*p)(1, 2));
        printf("%d\n", p(1, 2));
        printf("%d\n", add(1, 2));
        printf("%d\n", (*add)(1, 2));
        //todo 理解,将0强制类型转换为函数指针
        //todo 该函数指针返回值为void,没有参数
        //todo 之后解引用该函数指针并调用.
        //(*(void (*)()) 0)();
        //todo 理解,该语句为函数声明,signal是一个函数名称,
        //todo 它有两个参数,一个是int,一个是函数指针,
        //todo 函数指针有1个int的参数,返回值为void,
        //todo signal的返回值为一个函数指针,
        //todo 该函数指针有一个int参数,返回值为void.
        void (*signal(int, void (*)(int)))(int);
        //todo typedef 简化
        typedef void (*TC)(int);
        TC signal(int, TC);
        printf("%p %p\n", signal(1, NULL), signal);

        //* 函数指针数组.
        int (*parr[2])(int, int);
        parr[0] = add;
        printf("%d\n", parr[0](1, 2));
    }
    {
        //* 指向函数指针数组的指针.
        int (*pf)(int, int);
        int (*pfArr[4])(int, int);
        int (*(*pp)[4])(int, int) = &pfArr;
    }
    {
        //* 回调函数.
        void callback(int (*p)(int, int));
        int add(int x, int y);
        callback(add);
    }
    return 0;
}
/**
 * @brief  加
 * @note
 * @param  x:
 * @param  y:
 * @retval
 */
int add(int x,int y){
    return x + y;
}
void (*signal(int a, void (*b)(int)))(int){
    void (*q)(int) = signal;
    return q;
}
void callback(int (*p)(int,int)){
    printf("回调前\n");
    printf("%d\n",p(10, 22));
    printf("回调后\n");
}
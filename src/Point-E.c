#include <stdio.h>
int main(int argc, char const *argv[])
{
    char arr[] = "abcdef";
    char *p = arr;
    printf("%s\n", arr);
    printf("%s\n", p);
    //todo ָ���ַ�����ָ��,ָ�����ַ����׵�ַ,
    //todo ���ַ���Ϊ�����ַ���,�޷�����,�ɼ�const��ʾ����!.
    {
        const char *q = "test aaa";
        //*q = 'w';
        printf("%s\n", q);
    }
    {//todo �����ַ���.
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
    {//todo ����ָ��,ָ�������ָ��
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *p = arr;//todo ��ָͨ��
        printf("%p %p\n", p, p + 1);
        int(*q)[10] = &arr;//todo ����ָ��
        printf("%p %p\n", q, q + 1);//һ���������������С�ĵ�ַ.

        char *arr2[5];
        char *(*pa)[5] = &arr2;

        //�ʵ����÷�:��ά��������ʱʹ��.
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
        //todo ����ָ��,add,&add����ָ�����ĵ�ַ.
        int add(int, int);
        printf("%p\n", add);
        printf("%p\n", &add);
        //todo ��������������ɷ���ֵΪָ��ĺ�������.
        int (*p)(int, int) = add;
        printf("%p\n", *p);
        //todo ����ָ�����ʱ,����д*Ҳ���Բ�д
        printf("%d\n", (*p)(1, 2));
        printf("%d\n", p(1, 2));
        printf("%d\n", add(1, 2));
        printf("%d\n", (*add)(1, 2));
        //todo ���,��0ǿ������ת��Ϊ����ָ��
        //todo �ú���ָ�뷵��ֵΪvoid,û�в���
        //todo ֮������øú���ָ�벢����.
        //(*(void (*)()) 0)();
        //todo ���,�����Ϊ��������,signal��һ����������,
        //todo ������������,һ����int,һ���Ǻ���ָ��,
        //todo ����ָ����1��int�Ĳ���,����ֵΪvoid,
        //todo signal�ķ���ֵΪһ������ָ��,
        //todo �ú���ָ����һ��int����,����ֵΪvoid.
        void (*signal(int, void (*)(int)))(int);
        //todo typedef ��
        typedef void (*TC)(int);
        TC signal(int, TC);
        printf("%p %p\n", signal(1, NULL), signal);

        //* ����ָ������.
        int (*parr[2])(int, int);
        parr[0] = add;
        printf("%d\n", parr[0](1, 2));
    }
    {
        //* ָ����ָ�������ָ��.
        int (*pf)(int, int);
        int (*pfArr[4])(int, int);
        int (*(*pp)[4])(int, int) = &pfArr;
    }
    {
        //* �ص�����.
        void callback(int (*p)(int, int));
        int add(int x, int y);
        callback(add);
    }
    return 0;
}
/**
 * @brief  ��
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
    printf("�ص�ǰ\n");
    printf("%d\n",p(10, 22));
    printf("�ص���\n");
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int half(int number, int a[], int n);
int binsearch(int x, int v[], int n);
int factorial(int i);
void stringExpand(char s[]);
int maximumNumberOfConventions(int a, int b);
int primeNumber(int a);
void out99();
void start1();
void swap(int *, int *);
int leapYear(int n);

int main(int argc, char const *argv[])
{
    start1();
    return 0;
}


    /**
 * @brief  �ж�����
 * @note
 * @param  n: ��
 * @retval
 */
    int
    leapYear(int n)
{
    if (n%4==0&&n%100!=0)
    {
        return 1;
    }else if(n%400==0){
        return 1;
    }
    return 0;
};

/**
 * @brief  ������������
 * @note
 * @param  *a: ��1
 * @param  *b: ��2
 * @retval None
 */
void swap(int *a, int *b)
{
    int *temp = malloc(sizeof(int));
    *temp = *a;
    *a = *b;
    *b = *temp;
    free(temp);
}

void start1(){
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("��ͨ����:����Ϊ:%d\n", binsearch(3, v, 10));
    printf("���ַ�����:����Ϊ:%d\n", half(10, v, 10));
    // stringExpand("test string out!");
    int a = 6, b = 72;
    printf("%d��%d�����Լ��Ϊ:%d\n", a, b, maximumNumberOfConventions(a, b));
    // todo ���100��200֮�������
    int i;
    for (i = 100; i <= 200; i++)
    {
        if (primeNumber(i))
        {
            printf("%d ", i);
        }
    }
    // todo ����˷���
    // out99();

    // todo ����
    a = 10;
    b = 20;
    swap(&a, &b);
    printf("\n%d %d\n", a, b);

    // todo ����
    for (i = 2021; i <= 2050; i++)
    {
        if (leapYear(i))
        {
            printf("%d ", i);
        }
    }
}


/**
 * @brief  99�˷���
 * @note
 * @retval None
 */
void out99(){
    printf("\n");
    int i, j;
    for (i = 1; i <=9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d*%d=%-2d ", j, i, i * j);
        }
        printf("\n");
    }
}

/**
 * @brief  �ж��Ƿ�Ϊ����
 * @note
 * @param  a: ����1������
 * @retval ���
 */
int primeNumber(int a)
{
    // todo ��Ϊ2���ܱ�2����
    if (a % 2 == 0 && a != 2)
    {
        return 0;
    }
    int i = 3;
    for (; i <= sqrt(a); i += 2)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
};
/**
 * @brief  �����Լ��,շת�����
 * @note   ����Ҫ��С˳��,��С������Ϊ������˳������Լ��
 * @param  a: ��1
 * @param  b: ��2
 * @retval ���Լ��
 */
int maximumNumberOfConventions(int a, int b)
{
    //!��whileѭ��û��ִ��ʱ,���Լ��ΪС���Ǹ���
    int c = a > b ? b : a;
    //!���жϱ��ʽ����дΪc=a%b,����c��ֵһ���ᱻ����
    // todo ��a<bʱ,��һ��ѭ���Ὣ��������
    while (a % b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return c;
}
/**
 * @brief  �ݳ�ģʽ����ַ���
 * @note   ��֧��Ӣ��,���������ֽ��ַ�.
 * @param  s[]: ������ַ���
 */
void stringExpand(char s[])
{
    int end = strlen(s) - 1;
    int start = 0;
    char s2[255] = {0};
    int i = 0;
    for (i = 0; i <= end; i++)
    {
        s2[i] = '#';
    }
    for (; start <= end; end--, start++)
    {
        s2[start] = s[start];
        s2[end] = s[end];
        printf("%s\n", s2);
        Sleep(1000UL);
    }
}
/**
 * @brief  ���ַ�
 * @note
 * @param  number:��������
 * @param  a[]: ��������
 * @param  n: ����
 * @retval ����������-1
 */
int half(int number, int a[], int n)
{
    int top = 0, start = 0, end = n;
    while (start <= end)
    {
        top = (start + end) / 2;
        if (a[top] > number)
        {
            end = top - 1;
        }
        else if (a[top] < number)
        {
            start = top + 1;
        }
        else
        {
            return top;
        }
    }
    return -1;
}
/**
 * @brief  �ݹ����׳�
 * @note
 * @param  i: i�׳�
 * @retval ֵ
 */
int factorial(int i)
{
    if (1 == i)
        return 1;
    return i * factorial(i - 1);
}
/**
 * @brief  ���������Ƿ����ָ����
 * @note
 * @param  x: ���ҵ�����
 * @param  v[]: ����������
 * @param  n: ���������鳤��
 * @retval ��������������-1
 */
int binsearch(int x, int v[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}
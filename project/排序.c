#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // ���еļ�д
    // return arg1 - arg2; // ����ļ�д�������� INT_MIN ���ʧ�ܣ�
}
struct student
{
    char name[20];
    int age;
} s[3] = {{"����", 18}, {"����", 20}, {"����", 19}};
int compare_ints(const void *a, const void *b);
int compare_student(const void *a, const void *b);
void Swap(char *a, char *b, int size);
void user_bubble(void *a, int n, int size, int (*comp)(const void *, const void *));
int main(int argc, char const *argv[])
{
    {
        //*qsoft
        int ints[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
        int size = sizeof ints / sizeof *ints;
        qsort(ints, size, sizeof(int), compare_ints);
        for (int i = 0; i < size; i++)
        {
            printf("%d ", ints[i]);
        }
        printf("\n");
    }
    {
        user_bubble(s, 3, sizeof(struct student), compare_student);
        printf("%s %d\n", s[0].name,s[0].age);
        printf("%s %d\n", s[1].name, s[1].age);
        printf("%s %d\n", s[2].name, s[2].age);
    }
    return 0;
}
int compare_student(const void *a, const void *b){
    struct student *arg1 = (struct student *)a;
    struct student *arg2 = (struct student *)b;
    int t1 = (arg1->age > arg2->age) - (arg1->age < arg2->age);
    if (t1 == 0)
    {
        t1 = strcmp(arg1->name, arg2->name);
    }
    return t1;
}

/**
 * @brief  ��������
 * @note
 * @param  *a: �����׵�ַ
 * @param  n: ����Ԫ�ظ���
 * @param  size: ����Ԫ�ش�С
 * @param  *comp: �ȽϷ���
 * @retval None
 */
void user_bubble(void *a, int n,int size,int (*comp)(const void*,const void*))
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        //��ʼ����־����,������û�в�������,����Ϊ��������.
        flag = 1;
        //��һ�ν����ֵ�ŵ�n-1,��i�ηŵ�n-i-1��λ��
        for (j = 0; j < n - i - 1; j++)
        {
            if (comp((char *)a + j * size, (char *)a + (j+1) * size)>0)
            {
                Swap((char *)a + j * size, (char *)a + (j+1) * size,size);
                flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("������ǰ���,��ִ��%d��\n", i + 1);
            break;
        }
    }
}
void Swap(char* a,char *b,int size){
    int i = 0;
    for (i = 0; i < size; i++)
    {
        char tmp = *a;
        *a = *b;
        *b = tmp;
        a++;
        b++;
    }
}

#include <math.h>
#include <stdio.h>
#include <time.h>
#define N 2000000
#define OUT 0
#define TYPE long
int primeNumber(TYPE a);
void startRun1();
void startRun2();
void startRun3();
void startRun4();
/* N Ϊ���� 2~N��Χ�ڵ�����
 * OUT Ϊ�Ƿ��ҵ����������������̨
 * TYPE Ϊ���������,����������
 * * * */
/**
 * @brief  ȫ����������
 * @retval None
 */
TYPE count = 0;

int main(int argc, char const *argv[])
{
    //���������ṹ�壬����¼��ʼ�ͽ���ʱ��
    struct timeval start;
    struct timeval end;
    //��¼����ʱ���
    unsigned long diff;
    //todo ����1
    count = 0;
    //��һ�λ�ȡʱ�䣬����ʾ��ʼ��ʱ
    mingw_gettimeofday(&start, NULL);
    //�����Լ��ĳ���
    startRun1();
    //�ڶ��λ�ȡʱ�䣬����ʾ������ʱ
    mingw_gettimeofday(&end, NULL);

    //����ʱ������ӡ
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Ordinary Method:");
    printf("time:%10ld��s", diff);
    printf(",count:%ld\n", count);

    //todo ����2
    count = 0;
    //��һ�λ�ȡʱ�䣬����ʾ��ʼ��ʱ
    mingw_gettimeofday(&start, NULL);
    //�����Լ��ĳ���
    startRun2();
    //�ڶ��λ�ȡʱ�䣬����ʾ������ʱ
    mingw_gettimeofday(&end, NULL);

    //����ʱ������ӡ
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Optimization Method:");
    printf("time:%10ld��s", diff);
    printf(",count:%ld\n", count);

    //todo ����3
    count = 0;
    //��һ�λ�ȡʱ�䣬����ʾ��ʼ��ʱ
    mingw_gettimeofday(&start, NULL);
    //�����Լ��ĳ���
    startRun3();
    //�ڶ��λ�ȡʱ�䣬����ʾ������ʱ
    mingw_gettimeofday(&end, NULL);

    //����ʱ������ӡ
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Optimization Method:");
    printf("time:%10ld��s", diff);
    printf(",count:%ld\n", count);

    //todo ����4
    count = 0;
    //��һ�λ�ȡʱ�䣬����ʾ��ʼ��ʱ
    mingw_gettimeofday(&start, NULL);
    //�����Լ��ĳ���
    startRun4();
    //�ڶ��λ�ȡʱ�䣬����ʾ������ʱ
    mingw_gettimeofday(&end, NULL);

    //����ʱ������ӡ
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%-25s", "Optimization Method:");
    printf("time:%10ld��s", diff);
    printf(",count:%ld\n", count);

    return 0;
}
/**
 * @brief  �ж��Ƿ�Ϊ����,��׼�Գ���
 * @note
 * @param  a: ����1������
 * @retval ���
 */
int primeNumber(TYPE a)
{
    // todo ��Ϊ2���ܱ�2����
    if (a % 2 == 0 && a != 2)
    {
        return 0;
    }
    TYPE i = 3;
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
 * @brief  ��׼�Գ���
 * @note
 * @retval None
 */
void startRun1()
{
    TYPE i;
    if (N >= 2)
    {
        count++;
        if (OUT)
        {
            printf("2 ");
        }
    }
    // todo ������ʼ,������2�ı���
    for (i = 3; i <= N; i += 2)
    {
        if (primeNumber(i))
        {
            count++;
            if (OUT)
            {
                printf("%ld ", i);
            }
        }
    }
}
//!��Ҫ����Ϊȫ�ֱ���,�ֲ�������ʹ��ջ��.
TYPE a[N + 1] = {0};
/**
 * @brief  �ɱ�׼�Գ����Ż�
 * @note   ���ڿɶ���,�Ͳ����ڴ��Ż���,��a����洢��Ӧ������,ֻ��һλ��ʾ�Ƿ�Ϊ����
 * @retval None
 */
void startRun2()
{
    TYPE i, j;
    //todo ��ʼ�����в���2��������
    for (i = 3; i <= N; i += 2)
    {
        a[i] = i;
    }
    // todo ������ʼ,������2�ı���
    for (i = 3; i <= N; i += 2)
    {
        // todo ��������0ʱ����Ϊ����,����
        if (a[i] == 0)
        {
            continue;
        }
        if (primeNumber(a[i]))
        { // todo ������Ϊ����ʱ,��֮�ı���ȫ������
            for (j = 2 * a[i]; j <= N; j += a[i])
            {
                // todo ����Ϊ0ʱ����Ϊ����,����
                if (a[j] == 0)
                {
                    continue;
                }
                a[j] = 0;
            }
        }
        else
        {
            a[i] = 0;
        }
    }
    // todo ������
    if (N >= 2)
    {
        count++;
        if (OUT)
        {
            printf("2 ");
        }
    }
    // todo ������ʼ,������2�ı���
    for (i = 3; i <= N; i += 2)
    { // todo ����Ϊ0ʱ����Ϊ����,����
        if (a[i] == 0)
        {
            continue;
        }
        count++;
        if (OUT)
        {
            printf("%ld ", a[i]);
        }
    }
}

//!��Ҫ����Ϊȫ�ֱ���,�ֲ�������ʹ��ջ��.
TYPE a2[N + 1] = {0};
// todo ��������,ӦΪN/lnN,���Ϊ15%
TYPE list[N / 2 + 1] = {0};
/**
 * @brief  ɸ��
 * @note   δ�Ż��ڴ�
 * @retval None
 */
void startRun3()
{
    TYPE i, j, listCount = 0;
    //todo ��ʼ�����в���2��������
    for (i = 3; i <= N; i += 2)
    {
        a2[i] = i;
    }
    // todo ������ʼ,������2�ı���
    for (i = 3; i <= N; i += 2)
    {
        // todo ������������
        for (j = 0; j < listCount; j++)
        {
            // todo ���������ڱ���������ʱ�˳�
            if (list[j] > sqrt(a2[i]))
            {
                break;
            }
            // todo ������ʱ�˳�
            if (a2[i] % list[j] == 0)
            {
                break;
            }
        }
        // todo ��û�б���������Ϊ����,������������
        if (j >= listCount || list[j] > sqrt(a2[i]))
        {
            list[listCount] = a2[i];
            // todo ����������������1
            listCount++;
        }
    }
    // todo ������
    if (N >= 2)
    {
        count++;
        if (OUT)
        {
            printf("2 ");
        }
    }
    for (i = 0; i < listCount; i++)
    {
        count++;
        if (OUT)
        {
            printf("%ld ", list[i]);
        }
    }
}

//!��Ҫ����Ϊȫ�ֱ���,�ֲ�������ʹ��ջ��.
// todo ��������,ӦΪN/lnN,���Ϊ15%
TYPE list2[N / 2 + 1] = {0};
/**
 * @brief  ɸ��
 * @note   �Ż��ڴ�
 * @retval None
 */
void startRun4()
{
    TYPE i, j, listCount = 0;
    // todo ������ʼ,������2�ı���
    for (i = 3; i <= N; i += 2)
    {
        // todo ������������
        for (j = 0; j < listCount; j++)
        {
            // todo ���������ڱ���������ʱ�˳�
            if (list2[j] > sqrt(i))
            {
                break;
            }
            // todo ������ʱ�˳�
            if (i % list2[j] == 0)
            {
                break;
            }
        }
        // todo ��û�б���������Ϊ����,������������
        if (j >= listCount || list2[j] > sqrt(i))
        {
            list2[listCount] = i;
            // todo ����������������1
            listCount++;
        }
    }
    // todo ������
    if (N >= 2)
    {
        count++;
        if (OUT)
        {
            printf("2 ");
        }
    }
    for (i = 0; i < listCount; i++)
    {
        count++;
        if (OUT)
        {
            printf("%ld ", list2[i]);
        }
    }
}
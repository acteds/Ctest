#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>
void ReverseOrderString(char *s);
int main(int argc, char const *argv[])
{
    {
        int a[5] = {1, 2, 3, 4, 5};
        int *p = (int *)(&a + 1);//地址后移一个数组大小.
        printf("%d,%d\n", *(a + 1), *(p - 1));//2,5
    }
    {
        struct Test
        {
            int Num;
            char *pcName;
            short sDate;
            char cha[2];
            short sBa[4];
        }*p;
        p = (struct Test *)0x100000;
        printf("%d\n", sizeof(struct Test));
        printf("%p\n", p + 0x1);//+20,指针后移
        printf("%p\n", (unsigned long)p + 0x1);//+1,普通算数运算
        printf("%p\n", (unsigned int *)p + 0x1);//+4,指针后移
    }
    {
        int a[4] = {1, 2, 3, 4};
        int *p1 = (int *)(&a + 1);
        int *p2 = (int *)((int)a + 1);
        //todo 小端存储 01 00 00 00 02 00 00 00 ...
        //todo 所以指向了00,所以为00 00 00 02.
        printf("%x,%x\n", p1[-1], *p2);//!4,200000.
    }
    {
        //逗号表达式取最后一个值
        int a[3][2] = {(0, 1), (2, 3), (4, 5)};
        int *p = a[0];
        printf("%d\n", p[0]);//1
    }
    {
        int a[5][5];
        int(*p)[4];
        p = a;
        //打印两个指针间的元素个数.
        printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
    }
    {
        int a[10];
        //todo -5
        printf("%d\n", &a[0] - &a[5]);
    }
    {
        int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *p1 = (int *)(&aa + 1);
        int *p2 = (int *)(*(aa + 1));
        //todo 10,5
        printf("%d,%d\n", *(p1 - 1), *(p2 - 1));
    }
    {
        char *a[] = {"work", "at", "alibaba"};
        char **pa = a;
        pa++;
        printf("%s\n", *pa);//at
    }
    {
        char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
        char **cp[] = {c + 3, c + 2, c + 1, c};
        char ***cpp = cp;
        //todo *++cpp==c+2,*(c+2)=="POINT".
        printf("%s\n", **++cpp);//POINT
        //todo *++cpp==c+1,--(c+1)==c,*(c)+3=="ER"
        printf("%s\n", *--*++cpp + 3);//ER
        //todo cpp[-2]==c+3,*(c+3)=="FIRST",*(c+3)+3=="ST"
        printf("%s\n", *cpp[-2] + 3);//ST
        //todo cpp[-1][-1]=*(c+2-1),*(c+1)=="NEW",+1=="EW"
        printf("%s\n", cpp[-1][-1] + 1);//EW
    }
    //todo 简单的题目
    {
        unsigned long pA[] = {6, 7, 8, 9, 10};
        unsigned long *p;
        p = pA;
        *(p + 3) += 3;
        printf("%d,%d\n", *p, *(p + 3));
    }
    {
        //字符串转置.
        char a[] = "hello world";
        ReverseOrderString(a);
        printf("%s\n", a);
    }
    {
        //2+22+222
        int a, n, i, temp=0, sum=0;
        a = 2;
        n = 3;
        // scanf("%d%d", &a, &n);
        for (i = 0; i < n; i++)
        {
            temp = temp * 10 + a;
            sum += temp;
        }
        printf("%d\n", sum);
    }
    {
        //水仙花数
        int i = 0;
        for (i = 0; i < 100000; i++)
        {
            int n = 1, temp = i, sum=0;
            while (temp/10)
            {
                n++;
                temp /= 10;
            }
            temp = i;
            while (temp)
            {
                sum += pow(temp % 10, n);
                temp /= 10;
            }
            if (sum==i)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    {
        void pointDiamond(int n);
        //打印菱形.
        //pointDiamond(7);
    }
    {
        //喝饮料问题,2空瓶换1瓶
        int n = 20;
        int sum = 0;
        int temp = 0;
        sum = n;
        while (n>=2)
        {
            sum += n/2;//换来的
            n =n/2+ n % 2;//得到的空瓶
        }
        printf("%d\n", sum);
    }
    {
        //奇偶分类.
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},i=0;
        void oddAndEvenMumberClassification(int *a, int n);
        oddAndEvenMumberClassification(a, 10);
        for (i = 0; i < 10; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    {
        unsigned char a = 200, b = 100, c = 0;
        c = a + b;
        printf("%d %d\n", a + b, c);
    }
    {
        char a[1000]={0};
        int i;
        for (i = 0; i < 1000; i++)
        {
            a[i] = -1 - i;
        }
        printf("%d\n", strlen(a));
    }
    {
        //杨辉三角形
        char a[10][10] = {0},i,j;
        for ( i = 0; i < 10; i++)
        {
            //输出前缀6为5+1
            for (j = 0; j < (10-1-i)/2.0*6; j++)
            {
                printf(" ");
            }
            for (j = 0; j <= i; j++)
            {
                if (j==0||i==j)
                {
                    a[i][j] = 1;
                }else{
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                }
                printf("%-5d ", a[i][j]);
            }
            printf("\n");
        }
    }
    {
        //找凶手,一个说的假话,三个说的真话.
        int k = 0,n=0;
        for (k = 'a'; k < 'd'; k++)
        {
            n = 0;
            k != 'a' ? n++: n;
            k == 'c' ? n++ : n;
            k == 'd' ? n++ : n;
            k != 'd' ? n++ : n;
            if (n==3)
            {
                printf("%c\n", k);
                break;
            }
        }
    }
    {
        int aa[2][5] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int *p1 = (int *)(&aa + 1);
        int *p2 = (int *)(*(aa+1));
        //1,6
        printf("%d,%d\n", *(p1 -1), *(p2 - 1));
    }
    {
        //左旋字符串
        void leftShift(char *arr, int n);
        char a[11] = "hello word";
        leftShift(a, 2);
        printf("%s\n", a);
        //左旋判断
        char b[11] = "hello word";
        int detectionRotation(const char *a, const char *b);
        if (detectionRotation(a, b))
        {
            printf("%s是由%s左旋或右旋得来\n",a,b);
        }else{
            printf("%s不是由%s左旋或右旋得来\n", a, b);
        }
    }
    {
        //杨氏矩阵找数.
        int a[3][3] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}},x=0,y=0;
        int findNumber(int a[][3], int n, int m, int find,int *x,int *y);
        if (findNumber(a, 3, 3, 5,&x,&y))
        {
            printf("找到了,坐标为(%d,%d)\n",x,y);
        }
    }
    return 0;
}
/**
 * @brief  逆序字符串
 * @note   
 * @param  *s: 
 * @retval None
 */
void ReverseOrderString(char *s){
    assert(s);
    int n = strlen(s);
    char *end = s + n - 1;
    while (s<end)
    {
        char temp = *s;
        *s = *end;
        *end = temp;
        *s++;
        *end--;
    }
}
/**
 * @brief  打印菱形
 * @note   
 * @param  n: 要打印菱形上面的三角形的行
 * @retval None
 */
void pointDiamond(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (j = 0; j < i * 2 + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (i = n - 2; i >= 0; i--)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (j = 0; j < i * 2 + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
/**
 * @brief  奇偶数分类
 * @note
 * @param  *a:
 * @param  n:
 * @retval None
 */
void oddAndEvenMumberClassification(int *a,int n){
    int l = 0, r = n - 1;
    while (l<r)
    {
        while (a[l] % 2 == 1)
        {
            l++;
        }
        while (a[r] % 2 == 0)
        {
            r--;
        }
        if (l < r)
        {
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
        }
    }
}
/**
 * @brief  左旋
 * @note
 * @param  *arr:
 * @param  n: 左旋位数
 * @retval None
 */
void leftShift(char *arr,int n){
    int i = 0, len = strlen(arr);
    assert(arr);
    assert(n <= len);
    char a[255] = {0};
    for (i = 0; i < n; i++)
    {
        a[i]= arr[i];
    }
    strcpy(&arr[0], &arr[n]);
    for (i = 0; i < n; i++)
    {
        arr[len-n+i] = a[i];
    }
}
/**
 * @brief  判断字符串b是否通过左旋右旋字符串a得到
 * @note
 * @param  *a:
 * @param  *b:
 * @retval
 */
int detectionRotation(const char *a,const char *b){
    assert(a);
    assert(b);
    if (strlen(a)!=strlen(b))
    {
        return 0;
    }
    int length = strlen(a), n = 0, i = 0;
    const char *q = a;
    for (i = 0; i < length*2-1; i++)
    {
        if (b[n]==*q)
        {
            n++;
            if (n==length)
            {
                return 1;
            }
        }else{
            n = 0;
        }
        //当指针将要指向0时重置为初始位置
        if (i==length-1)
        {
            q = a;
        }else{
            q++;
        }
    }
    return 0;
}
/**
 * @brief  杨氏矩阵,找数
 * @note
 * @param  a[][3]:
 * @param  n:   列数
 * @param  m:   行数
 * @param  find:    要查找的数
 * @param  *x:  x坐标
 * @param  *y:  y坐标
 * @retval
 */
int findNumber(int a[][3],int n,int m,int find,int *x,int *y){
    int i = 0, j = n-1;
    while (j>=0)
    {
        if (a[i][j]>find)
        {
            j--;
        }else if (a[i][j]<find)
        {
            i++;
        }else{
            *x = i;
            *y = j;
            return 1;
        }
    }
    return 0;
}
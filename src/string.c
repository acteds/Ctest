#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
void user_strcpy(char *q, const char *p);
void user_strcat(char *q, const char *p);
int user_strcmp(const char *q, const char *p);
const char *user_strstr(const char *p, const char *q);
void user_memcpy(void *d, const void *src, size_t num);
void user_memmove(void *d, const void *src, size_t num);
int user_memcmp(const void *desc, const void *src, size_t num);
int main(int argc, char const *argv[])
{

    {
        char a[] = "abcdefghijk", b[] = "cmd";
        user_strcpy(a, b);
        printf("%s\n", a);
    }
    {
        char a[20] = "hello ", b[] = "word";
        user_strcat(a, b);
        printf("%s\n", a);
    }
    {
        char a[20] = "abcde", b[] = "abcdef";
        printf("%d\n", user_strcmp(a, b));
    }
    {
        char a[20] = "aabbbcdef", b[] = "bbc";
        printf("%s\n", user_strstr(a, b));
    }
    {
        char a[20] = "192.168.1.128";
        char b[20];
        user_strcpy(b, a);
        char *r = NULL;
        for (r = strtok(b, "."); r != NULL; r = strtok(NULL, "."))
        {
            printf("%s ", r);
        }
        printf("\n");
    }
    {
        //strerror,翻译错误码为错误信息.
        //errno为全局错误码,当程序出错时被赋值相应错误码
        FILE *f = fopen("test.txt", "r");
        if (f == NULL)
        {
            printf("%s\n", strerror(errno));
        }
    }
    { //ctype.h
        char arr[] = "It is to lower";
        printf("%c\n", tolower(*arr));
    }
    {
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8};
        int b[10] = {0};
        user_memcpy(b, a, sizeof(a));
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            printf("%d ", b[i]);
        }
        printf("\n");
    }
    { //重叠内存的复制
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        user_memmove(&a[5], &a[2], 20);
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    {
        //内存比较
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8};
        int b[10] = {3};
        user_memcpy(b, a, sizeof(a));
        printf("%d\n", user_memcmp(a, b, 40));
    }
    {
        //设置内存
        char a[10] = "";
        memset(a, 'x', 9);
        printf("%s\n", a);
        int arr[10] = {0};
        memset(arr, 0xff, 10);
        int i;
        for (i = 0; i < 10; i++)
        {
            printf("%x ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
/**
 * @brief  strcpy
 * @note
 * @param  *q:
 * @param  *p:
 * @retval None
 */
void user_strcpy(char *q, const char *p)
{
    assert(q != NULL);
    assert(p != NULL);
    while (*p)
    {
        *q++ = *p++;
    }
    *q = 0;
}
/**
 * @brief  strcat
 * @note
 * @param  *q:
 * @param  *p:
 * @retval None
 */
void user_strcat(char *q, const char *p)
{
    assert(q != NULL);
    assert(p != NULL);
    while (*q)
    {
        q++;
    }
    while (*p)
    {
        *q++ = *p++;
    }
    *q = 0;
}
/**
 * @brief  strcmp
 * @note   
 * @param  *q: 
 * @param  *p: 
 * @retval 
 */
int user_strcmp(const char *q, const char *p)
{
    assert(q != NULL);
    assert(p != NULL);
    while (*q && *p)
    {
        if (*q == *p)
        {
            q++;
            p++;
        }
        else
        {
            break;
        }
    }
    return *q - *p;
}
const char *user_strstr(const char *p, const char *q)
{
    assert(p != NULL);
    assert(q != NULL);
    const char *m = q;
    const char *t = p;
    if (*q == '\0')
    {
        return NULL;
    }
    while (*t)
    {
        //比较子串
        while (*m == *t)
        {
            m++;
            t++;
            //若子串到头则返回起始位置
            if (*m == '\0')
            {
                return p;
            }
        }
        //当前p位置子串查找失败,归位m,p后移,并同步t;
        if (*m != '\0')
        {
            m = q;
            p++;
            t = p;
        }
    }
    return NULL;
}
/**
 * @brief  memcpy
 * @note   不重叠内存间的复制.
 * @param  *d: 
 * @param  *src: 
 * @param  num: 
 * @retval None
 */
void user_memcpy(void *d, const void *src, size_t num)
{
    assert(d != NULL);
    assert(src != NULL);
    while (num--)
    {
        *(char *)d = *(char *)src;
        (char *)d++;
        (char *)src++;
    }
}
/**
 * @brief  memmove
 * @note   重叠内存间的复制.
 * @param  *d: 
 * @param  *src: 
 * @param  num: 拷贝的内存大小,字节
 * @retval None
 */
void user_memmove(void *desc, const void *src, size_t num)
{
    assert(desc != NULL);
    assert(src != NULL);
    char *c_desc = (char *)desc;
    const char *c_src = (char *)src;
    if (c_desc < c_src)
    {
        while (num--)
        {
            *c_desc = *c_src;
            c_desc++;
            c_src++;
        }
    }
    else if (c_desc > c_src)
    {
        c_desc += num - 1;
        c_src += num - 1;
        while (num--)
        {
            *c_desc = *c_src;
            c_desc--;
            c_src--;
        }
    }
}
int user_memcmp(const void *desc, const void *src, size_t num)
{
    assert(desc != NULL);
    assert(src != NULL);
    const char *a = (char *)desc;
    const char *b = (char *)src;
    while (num--)
    {
        if (*a != *b)
        {
            return *a - *b;
        }
        a++;
        b++;
    }
    return 0;
}

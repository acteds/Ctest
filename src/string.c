#include <stdio.h>
#include <assert.h>
void user_strcpy(char *q, const char *p);
void user_strcat(char *q, const char *p);
int user_strcmp(const char *q, const char *p);
char *user_strstr(const char *p, const char *q);
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
char *user_strstr(const char *p, const char *q)
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
        if(m!='\0')
        {
            m = q;
            p++;
            t = p;
        }
    }
    return NULL;
}
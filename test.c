#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char ch;
    while ((ch = getchar()) != '#')
    {
        putchar(ch);
    }
    return 0;
}

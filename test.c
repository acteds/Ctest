#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char ch='w';
    char*pc=&ch;
    printf("%d",sizeof(pc));
    return 0;
}

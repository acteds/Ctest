#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    short price;
}person;

int main(int argc, char const *argv[])
{
    person p={"Êé1",20};
    person *p2=&p;
    printf("name=%s,price=%d\n", p.name,p.price);
    printf("name=%s,price=%d\n", (*p2).name,(*p2).price);
    printf("name=%s,price=%d\n", p2->name,p2->price);
    return 0;
}

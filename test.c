#include <stdio.h>
#define MAX 10
enum Sex{
    MALE,FEMALE,SECRET
};
int main(int argc, char const *argv[])
{
    enum Sex s=FEMALE;
    printf("%d",s);
    return 0;
}

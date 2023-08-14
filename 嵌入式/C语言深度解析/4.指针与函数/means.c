#include <stdio.h>

int main(void)
{

    int code  a = 10;

    int *p = &a;

    *p = 2;
    
    printf("%d\n", a);

    return 0;
}
#include <stdio.h>

#define NUM1

int main(void)
{
    int a = 0;
    
    #ifdef NUM1
    a += 10;
    #endif
    
    #ifdef NUM2
    a += 1000;
    #endif

    printf("%d", a);

    return 0;
}
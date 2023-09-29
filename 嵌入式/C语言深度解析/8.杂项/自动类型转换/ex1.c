#include <stdio.h>

int main(void)
{
    unsigned int a = 100;
    
    //不会进入这个循环
    //while(a>-1)
    //不会退出这个循环
    printf("%ld\n", (long)-1);
    printf("%ld\n", (long)a);
    /*while(a>-1L)
    {
        //printf("%d\n", a);
        --a;
    }*/

    printf("%d\n", a);

    return 0;
}
#include <stdio.h>
#ifndef stdout
#error macro stdout not defined, please include stdio.h

#endif

int main(void)
{
    fprintf(stdout, "hello world\n"); //等价于printf("hello world\n");
    
    return 0;
}
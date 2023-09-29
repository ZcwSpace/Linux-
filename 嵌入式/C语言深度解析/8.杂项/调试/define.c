
#include <stdio.h>
#include <stdlib.h>

#define print_error(str) \
do{\
        fprintf(stderr, "File %s, Line %d, Function %s error\n", __FILE__, __LINE__, str);\
        perror("error Reason");\
        exit(-1);\
}while(0);

int fun(int **p, long size)
{
        *p = malloc(size);
        if(NULL == *p) print_error( "malloc");
}

int main(void)
{
    int ret = 0;
    int *p = 0;
    long size = sizeof(int)*4000000000000000000; 
    
    ret = fun(&p, size);
    
    return 0;
}
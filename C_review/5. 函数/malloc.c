#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void * ptr;

    ptr=malloc(0);

    if(ptr==NULL)
    {
        printf("malloc调用失败\n");
    }

    return 0;
}
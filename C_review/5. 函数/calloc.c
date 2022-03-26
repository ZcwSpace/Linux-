#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int * ptr;
    int num=5;

    ptr=calloc(num,4);
    if(ptr==NULL)
    {
        printf("calloc调用失败\n");
    }
    for(int i=0;i<num;i++)
    {
        printf("%d\n",ptr[i]);
    }
    free(ptr);

    return 0;
}
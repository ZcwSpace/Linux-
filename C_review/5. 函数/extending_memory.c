#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int * ptr1,*ptr2;
    int num=5;

    ptr1=malloc(num*4);
    if(ptr1==NULL)
    {
        printf("malloc调用失败\n");
    }
    //发现分配的存储空间不够用，重新分配
    ptr2=malloc(2*num*4);
    if(ptr2==NULL)
    {
        printf("malloc调用失败\n");
    }
    //复制存储空间
    memcpy(ptr2,ptr1,4);
    free(ptr1);
    //进行一些列操作
    free(ptr2);

    return 0;
}
#include <stdio.h>

int main()
{
    int *p;

    p=&p;

    printf("当前指针的地址为：%p\n",p);

    return 0;
}
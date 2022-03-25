#include <stdio.h>

int main(main)
{
    register int i=520;
    
    printf("i's addr:%p\n",&i);//不能对register变量进行取地址操作

    return 0;
}
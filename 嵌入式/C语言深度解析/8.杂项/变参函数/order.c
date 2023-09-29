#include "stdio.h"
		
void fun(int a, int b, int c, int d)
{
    printf("%p\n", &a);//高
    printf("%p\n", &b);
    printf("%p\n", &c);
    printf("%p\n", &d);//低
    //从左到右入栈
}

int main(void)
{
    fun(20, 34, 42, 43);

    return 0;
}
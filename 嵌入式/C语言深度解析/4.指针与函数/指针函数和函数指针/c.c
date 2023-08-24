#include<stdio.h>

int fun1(int a)
{
    //...
}

int fun2(int a, int b)
{
    //...
}

int fun3(int a, int b, float c)
{
    //...
}

int main(void)
{
    int (*funp)() = NULL;   //赋NULL的时候不需要进行类型的强制转换

    funp = fun1;
    funp(10);
    
    funp = fun2;
    funp(23, 45);
    
    funp = fun3;
    funp(23, 45, 34.65);
}
#include<stdio.h>

int fun(int a, float b)
{
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}

int main(void)
{
    int (*funp)() = (int (*)())fun; //定义时将参数省略
    
    fun(10);             //可以
    fun(10, 12.4);       //可以
    fun(21, 34.5, 3453); //可以
}
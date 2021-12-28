#include<stdio.h>
//void(*)();
//int *(void a);
int func();
int fun2(int a);  
int main(void)
{
    printf("%d",fun2(func()));
}
int func()
{
    return 5;
}
int fun2(int a)
{
    return a;
}
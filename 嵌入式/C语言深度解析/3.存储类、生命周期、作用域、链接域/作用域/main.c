#include <stdio.h>

//没有fun函数的声明
//extern float fun(float a, float b);

int main(void)
{
    float ret = 0;
    
    ret = fun(100.0, 200.0);

    printf("ret = %f\n", ret);

    return 0;
}
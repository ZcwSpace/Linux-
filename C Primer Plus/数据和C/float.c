#include <stdio.h>

int main(void)
{
    printf("%d %d %d\n",sizeof(float),sizeof(double),sizeof(long double));// 32 64 128
    //可以没有小数点
    float num=2e5;
    //可以没有指数部分
    float num2=19.2;
    //可以省略小数部分
    float num3=19.e16;
    //可以省略整数部分
    float num4=.16;
    //默认情况下，编译器认为浮点型常量为double类型
    float some=3.0*2.0;//这样做运算速度更慢
    some=3.0F*2.0F;
    //16进制
    some=0xa.1fp10;//(10+1/16+15/256)*1024

    return 0;
}
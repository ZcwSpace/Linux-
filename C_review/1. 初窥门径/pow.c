#include <stdio.h>
#include <math.h>

int main(void)
{
    //int result =pow(2,32)-1;
    unsigned int result =pow(2,32)-1;
    //sqrt：C 库函数 double sqrt(double x) 返回 x 的平方根。

    printf("result=%u\n",result);

    return 0;
}
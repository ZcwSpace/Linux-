#include <stdio.h>
#define PI 3.1415926

int main()
{
    float r,grith,area;

    printf("请输入一个圆的半径：");
    scanf("%f",&r);

    grith=2*PI*r;
    area=PI*r*r;

    printf("周长=%.2f,面积=%.2f：",grith,area);

    return 0;
}
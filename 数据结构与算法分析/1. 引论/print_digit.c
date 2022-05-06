//编写一个程序以输出任意实数（可以是负的）
#include <stdio.h>

void print_digital(float n);
int main(void)
{
    float n;

    printf("请输入数字：");
    scanf("%f",n);
    if(n<0)
    {
        putchar('-');
    }
    print_digital(n);

    return 0;
}

void print_digital(float n)
{
    if(n<0)
    {
        print_digital(n*10);
        printf("%f",n*10-n);
    }
    else
    {
        print_digital(n/10);
        printf("%f",n-n/10);
    }
}

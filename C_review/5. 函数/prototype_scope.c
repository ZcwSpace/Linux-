#include <stdio.h>

void b(int a);//函数的参数在声明时可以不写参数名或者写任意参数名

int main(void)
{
    b(5);

    return 0;
}
void b(int temp)
{
    printf("temp=%d\n",temp);
}
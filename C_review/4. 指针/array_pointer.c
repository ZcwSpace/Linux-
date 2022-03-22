#include <stdio.h>

int main(void)
{
    int a[]={1},int b[]={0},*p_a;

    a=b;// 报错原因：表达式必须是可修改的左值
    p_a=b;

    return 0;
}
#include <stdio.h>

void b();


int main(void)
{
    goto label;

    label:printf("goto first label");
    //label:;//由于函数作用域的影响，在函数内部不能定义相同的标签
}


    
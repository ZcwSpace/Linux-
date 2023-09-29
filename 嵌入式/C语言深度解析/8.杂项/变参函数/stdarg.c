//*#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef char* va_list;
//va_list ap;

//va_start(ap, prev_param)//ap:第一个变参 prev——param：最后一个固定参数
//va_arg(ap, type)//ap:当前空间 type:当前空间的类型
//va_end(ap):将ap赋值为空，防止ap变为野指针
#include "stdio.h"
#include <stdarg.h> //必须包含

void fun(char *fmt, ...)
{
    int i = 0;

    va_list ap; //等价于char *ap

    va_start(ap, fmt); //让ap指向f...中的第一个参数

    for(i=0; i < strlen(fmt); i++)
    {
        switch(fmt[i])
        {
            //c、s、i都以int解释
            case 'c':
            case 's':
            case 'i':
                printf("%d\n", *((int *)ap));
                va_arg(ap, int);  	//指向下一个变参空间
                break;

            //f、double都以double解释
            case 'f':
            case 'd':
                printf("%lf\n", *((double *)ap));
                va_arg(ap, double);	//指向下一个变参空间
                break;
        }
    }

    va_end(ap); //等价于ap = NULL
}

int main(void)
{
    int a = 10;
    char b = 'a';
    float c = 123.56;
    
    //"icf"为 a b c各自对应的格式，对应关系必须一致，不能颠倒，否则解释就会出错
    fun("icf", a, b, c);

    return 0;
}
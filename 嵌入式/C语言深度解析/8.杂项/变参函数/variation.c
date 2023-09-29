#include <stdio.h>

void fun(char *fmt, ...)
{
    //获取...中每一个变参的值，然后进行处理
    char * p = fmt;

    printf("%s\n", p);
    printf("%d\n", *(p - sizeof(char *)));
    printf("%c\n", *(p - sizeof(char *) * 2));
    printf("%s\n", p - sizeof(char *) * 3);
}

int main(void)
{	
    fun("xxx", 10, 'a', 123.56);
    
    return 0;
}	
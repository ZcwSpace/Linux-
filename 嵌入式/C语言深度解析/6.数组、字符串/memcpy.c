#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(void)
{
    printf("hello world\n");
}

int main()
{
    char buf[30] = {0};
    char (*p)[30] = &buf;

    fun();
    memcpy(buf, fun, 30);
    
}
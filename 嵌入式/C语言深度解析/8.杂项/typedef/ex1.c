#include <stdio.h>

//可以多次重命名
typedef unsigned int unit;
typedef unit u32;

typedef char *charp;
charp p1,p2;

#define charp1 char *
charp1 p3, p4;
__int32_t add;

int main()
{
    printf("p1 = %d\n",sizeof(p1));
    printf("p2 = %d\n",sizeof(p2));
    printf("p3 = %d\n",sizeof(p3));
    printf("p4 = %d\n",sizeof(p4));
    printf("add = %d\n",sizeof(add));
    
    return 0;
}
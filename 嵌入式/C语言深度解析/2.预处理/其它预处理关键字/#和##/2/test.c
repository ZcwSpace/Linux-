#include <stdio.h>

int main()
{
    char a = '5';
    char* addr = &a;

    printf(addr);
    //putchar(addr);

    return 0; 
}
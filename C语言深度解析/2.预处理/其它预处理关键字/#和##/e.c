#include <stdio.h>

#define MACRO1 #helloworld
#define MACRO2 hello##world

int main(void)
{
    MACRO1;
    MACRO2;
    
    return 0;
}
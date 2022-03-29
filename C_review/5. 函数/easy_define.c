#include <stdio.h>
#define PI 3.14
#define R 2
#define S PI*R*R
int main(void)
{
    printf("S=%f\n",S);
#undef PI 
    //printf("S=%d",S);
}
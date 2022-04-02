#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>

int main(void)
{
    int n=4,m=5;
    float f=7.0f,g=8.0f;

    printf("%d\n",n,m);
    printf("%d %d %d\n",n);
    printf("%d %d\n",f,g);
    /*4
4 1970051264 0
31998560 1970051264*/

    return 0;
}
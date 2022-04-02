#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>

int main(void)
{
    float a;

    printf("%zd \n",sizeof a);//4

    return 0;
}
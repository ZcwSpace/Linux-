#define MAX 256
#include <stdio.h>

int main(void)
{
    unsigned char A[MAX] = {},i;  //i被定义为unsigned char
    //printf("%d\n", A[1000]);

    for (i=0; i<MAX; i++)
    {
        A[i]=i;//不会报错吗？0
        //printf("%d\n", A[i]);
    }
}
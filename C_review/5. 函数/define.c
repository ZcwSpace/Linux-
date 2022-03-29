#include <stdio.h>
#define MAX(x,y) ((x)>(y) ? (x):(y))
#define SQUARE(x) x*x 
int main(void)
{
    printf("MAX=%d\n",MAX(1,2));
    printf("5的SQUARE=%d\n",SQUARE(5+1));//5+1*5+1=5+5+1=11？？
    printf("3.1的SQUARE=%d\n",SQUARE(3.1));//3.1的SQUARE=10621536
    return 0;
}
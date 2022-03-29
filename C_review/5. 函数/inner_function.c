#include <stdio.h>
#define SQUARE(x) ((x)*(x)) 

int main(void)
{
    inline int square(int x)
    {
        return x*x;
    }
    int i=1;
    /*得不到想要的结果
    while(i<=5)
    {
        printf("%d的平方值为%d\n",i-1,SQUARE(i++));//i++*i++
    }
    */
    while(i<=5)
    {
        printf("%d的平方值为%d\n",i-1,square(i++));//i++*i++
    }

    return 0;
}



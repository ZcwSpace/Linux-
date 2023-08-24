#include <stdio.h>

int fun(int n)
{
    int ret = 0;

    if(n == 1) return 1;
    else    
    {
        ret = n + fun(n-1);     
        ret = ret + n + fun(n-1);
    }

    return  ret;
}

int main(void)
{
    int ret = 0;

    ret = fun(2);

    printf("%d\n", ret);

    return 0;
}
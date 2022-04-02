#include <stdio.h>

int main(void)
{
    //long long int num=010L;
    int num=010LL;

    printf("%d\n",num);
    printf("%d\n",sizeof(long));
    printf("%d\n",sizeof(long long));
    printf("%d\n",sizeof num);


    return 0;
}
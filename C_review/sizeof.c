#include <stdio.h>

int main(void)
{
    int num=5;

    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(num));
    printf("%d\n",sizeof num);

    return 0;
}
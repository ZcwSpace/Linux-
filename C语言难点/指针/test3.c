#include<stdio.h>

int square(int);

int main()
{
    int num=5;
    int (*fp)(int num);

    fp=square;

    printf("%d\n",fp(num));
    
    return 0;
}
int square(int num)
{
    return num*num;
}

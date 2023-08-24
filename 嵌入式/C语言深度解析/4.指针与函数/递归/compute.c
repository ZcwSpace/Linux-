#include <stdio.h>

int main()
{
    int sum;

    sum = 99.0 / 2 * (1 + 99);

    printf("%d\n", sum); 

    sum = 0;
    for(int i = 1; i < 100; i++)
    {
        sum += i;
    }
    printf("%d\n", sum); 

    return 0;
}
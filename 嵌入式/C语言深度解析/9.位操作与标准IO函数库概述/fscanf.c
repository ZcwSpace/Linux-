#include <stdio.h>

int main()
{
    int a, b, c;

    int ret = fscanf(stdin, "%d %d %d", &a, &b, &c);
    printf("%d\n", ret);

    return 0;
}
#include <stdio.h>

int main()
{
    char buf[5];

    scanf("%s", buf);
    printf("%s", buf);//段错误

    return 0;
}
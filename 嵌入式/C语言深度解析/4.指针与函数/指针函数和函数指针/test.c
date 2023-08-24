#include <stdio.h>

void fun(int buf[5]);

int main()
{
    int buf[5];

    fun(buf);

    return 0;
}
void fun(int buf[5])
{
    printf("%d", sizeof(buf));
}
#include <stdio.h>

void print_fun(int type, void *arg)
{
        if(1 == type)
        {
                printf("%d\n", *((int *)arg));
        }
        else if(2 == type)
        {
                printf("%f\n", *((float *)arg));
        }
        else if(3 == type)
        {
                printf("%s\n", (char *)arg);
        }
}

int main(void)
{
        int a = 100;
        float b = 20.45;
        char *str = "hello world";

        print_fun(1, (void *)&a);
        print_fun(2, (void *)&b);
        print_fun(3, (void *)str);

        return 0;
}
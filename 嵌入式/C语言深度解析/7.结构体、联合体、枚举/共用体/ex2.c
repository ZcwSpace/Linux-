#include <stdio.h>

union Un_Arg
{
    int arg1;
    float arg2;
    char *arg3;
};

void print_fun(int type, union Un_Arg arg)
{
    if(1 == type)
    {
            printf("%d\n", arg.arg1);
    }
    else if(2 == type)
    {
            printf("%f\n", arg.arg2);
    }
    else if(3 == type)
    {
            printf("%s\n", arg.arg3);
    }
}

int main(void)
{
    int a = 100;
    float b = 20.45;
    char *str = "hello world";
    union Un_Arg arg;

    arg.arg1 = a;
    print_fun(1, arg);
    arg.arg2 = b;
    print_fun(2, arg);
    arg.arg3 = str;
    print_fun(3, arg);

    return 0;
}
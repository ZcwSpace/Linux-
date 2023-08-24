#include <stdio.h>

int func(int a, float b)
{
    //...
}

int main()
{
    int (*funp)(void);
    //func(100); //报参数太少的错误
    func(200, 12.3, 324); //报参数太多的错误
}
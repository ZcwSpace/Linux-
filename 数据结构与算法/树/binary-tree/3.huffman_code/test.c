#include <stdio.h>

void f(int *p)
{
    int b=5;
    *p=b;
    printf("%p\n",p);
}

int main()
{
    int a=5,*p;
    
    p=&a;
    printf("%p\n",p);
    f(p);

    return 0;

}
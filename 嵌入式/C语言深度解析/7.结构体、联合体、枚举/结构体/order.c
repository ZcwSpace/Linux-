#include <stdio.h>

struct A
{
    int    a;
    char   b;
    short  c;
};

struct B
{
    char   b;
    int    a;
    short  c;
};

int main()
{
    printf("%d\n", sizeof(struct A));  //打印结果：8
	printf("%d\n", sizeof(struct B));  //打印结果：12

    struct A a;

    printf("%p\n",&a.b);
    printf("%p\n",&a.c);

    return  0;
}
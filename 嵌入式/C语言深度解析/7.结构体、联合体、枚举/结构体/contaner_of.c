#include <stdio.h>

#define offsetof(TYPE, MEMBER)		((int) & (((TYPE *)0)->MEMBER))
#define container_of(ptr, type, member) (type *)(ptr - offsetof(type, member))
//(struct Test *)((char *)&ts.c - ((int) & (((struct Test *)0)->c)))

struct Test
{
    char a;
    int b;
    short c;
}ts = {'a', 100, 10};

int main(void)
{	
    printf("%d\n", &ts);
    printf("container_of(&ts.c, struct Test, c) = %d\n",  container_of(&ts.c, struct Test, c));
    
    return 0;
}	
//#include <stddef.h>
#include <stdio.h>

#define offsetof(TYPE, MEMBER)		((int) & (((TYPE *)0)->MEMBER))
//((int) & (((struct Test *)0)->c))
		
struct Test
{
    char a;
    int b;
    short c;
}ts = {'a', 100, 10};

int main(void)
{	
    int offset = 0;
    
    offset = (int)&(ts.c) - (int)&ts;
    printf("&ts.c - &ts	= %d\n", offset);
    
    offset = offsetof(struct Test, c);
    printf("offset 	    = %d\n", offset);
    
    return 0;
}	
#include <stdio.h>

int main(void)
{
    /*
    int *p = NULL;
    *p = 200;

    return 0;
    */
   int a = 100;
	void *p = (void *)&a;
	
	*p = 200;  
}
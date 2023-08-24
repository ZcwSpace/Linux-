#include <stdio.h>		

extern int fun(int (*funp)());

static int fun1(int a)																		
{																					
	printf("%d\n", a);																		
}																					
int main()																					
{		
	fun(fun1);
	return 0;
}
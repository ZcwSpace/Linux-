#include <stdio.h>

int (*g_funp)() = NULL;									

int fun(int (*funp)())      						
{                       								
	funp(100);
																					
	
	g_funp = funp;                          
}					
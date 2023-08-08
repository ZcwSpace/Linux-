#include <stdio.h>
					
#define PI 3.14
					
int main(void)
{
    
#ifdef PI 
    printf("%f\n", PI); 
    
#else 
# error PI not defined 
    
#endif	
    
    return 0;
}
#include <stdio.h>
					
#define ADDR1 0x12343654
#define ADDR2 0x54543243

#define MACRO(a, b) a##b	

int main(void)
{	
    int *p = MACRO(ADDR, 1);

    printf("%p", p);
    
    return 0;
}	
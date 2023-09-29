#include <stdio.h>
			
int main(void)
{
    char buf[10]; 
    
    fgets(buf, sizeof(buf), stdin);
    printf("%s\n", buf);
    
    return 0;
}
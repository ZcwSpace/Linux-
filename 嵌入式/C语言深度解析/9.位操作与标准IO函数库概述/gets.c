#include <stdio.h>
#include <stdlib.h>
			
int main(void)
{
    char buf[10] = {0};
    gets(buf); 
    
    puts(buf);

    char buf1[5] = {'a', 'a', 'a', 'a', 'a', 'a',};

    return 0;
}
#include <stdio.h>
					
#define STR1(s) #s" wolrd"
#define STR2(s) "hello "#s

int main(void)
{
    printf("%s\n", STR1(hello));
    printf("%s\n", STR2(world));
                    
    return 0;
}    
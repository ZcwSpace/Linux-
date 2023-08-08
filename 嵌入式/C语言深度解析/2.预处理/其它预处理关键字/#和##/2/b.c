#include <stdio.h>

#define NUM 100
#define STR(num) #num

int main(void)
{
                printf("%s\n", STR(NUM));

                return 0;
}
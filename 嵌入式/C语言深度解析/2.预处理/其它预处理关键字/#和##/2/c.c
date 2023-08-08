#include <stdio.h>

#define NUM 100
#define STR(num) #num
#define _STR(num) STR(num)

int main(void)
{
    printf("%s\n", _STR(NUM));

    return 0;
}
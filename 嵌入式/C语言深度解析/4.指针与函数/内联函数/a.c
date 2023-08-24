#include <stdio.h>
#include "inline.h"

int my_max()
{
;
}
int main(void)
{
    int ret = 0;
    
    ret = my_max(25 ,30);
    
    printf("ret = %d\n", ret);
    
    return 0;
}
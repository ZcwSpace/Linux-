#include <stdio.h>

int main(void)
{
    int num=1;

    printf("%d+%d=%d\n",num);

    printf("%o,%x\n",8,16);
    
    printf("%#o,%#x\n",8,16);
    printf("%#X\n",8,16);
    printf("%#X\n",16);

    /*输出
    1+19041816=-229374184
    10,10
    010,0x10
    0X8
    0X10*/

    return 0;
}
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int32_t num;
    
    printf("int32_t:%d\n",sizeof num);//32

    int_least8_t num2;

    printf("int_least8_t:%d\n",sizeof num2);//8

    int_fast8_t num3;

    printf("int_fast8_t:%d\n",sizeof num3);//8

    intmax_t num4;

    printf("intmax_t:%d\n",sizeof num4);//64

    uintmax_t num5;

    printf("uintmax_:%d\n",sizeof num5);//64

    return 0;
}

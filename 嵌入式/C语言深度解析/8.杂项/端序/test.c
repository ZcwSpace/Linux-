#include <stdio.h>

union un
{
        int a;
        char b;
}test;

int main(void)
{
        test.a = 0x12345678;     //  0x12     0x34     0x56     0x78
        printf("%x\n", test.b);  //?00010010 00110100 01010110 01111000?
        
        if(test.b == 0x78)
        {
                printf("Little-endain：LSB in low Byte\n");
        }
        else if(test.b == 0x12)
        {
                printf("Big-endain：MSB in low Byte\n");
        }

        return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int * ptr;
    int num=5;

    ptr=malloc(num*4);
    if(ptr==NULL)
    {
        printf("malloc调用失败\n");
    }
    memset(ptr,5,num*4);//指针 想要赋予的值 空间的大小
    /*
    memset是按字节赋值的，取变量a的后8位二进制进行赋值。

    1的二进制是（00000000 00000000 00000000 00000001），取后8位（00000001），int型占4个字节，
    当初始化为1时，它把一个int的每个字节都设置为1，也就是0x01010101,
    二进制是00000001 00000001 00000001 00000001，十进制就是16843009。
    */
    for(int i=0;i<num;i++)
    {
        printf("%d\n",ptr[i]);
    }
    free(ptr);

    return 0;
}
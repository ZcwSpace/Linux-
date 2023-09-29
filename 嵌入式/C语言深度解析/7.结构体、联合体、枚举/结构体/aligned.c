#include <stdio.h>

struct kk2
{       
    char a;	 			//1<32，a的对齐值为1	
    short b; 			//2<32，b的对齐值为2	
    int c;			 	//4<32，b的对齐值为4		
    long long d; 	//8<32，d的对齐值为8
}__attribute__((aligned(32))) yy2;    //yy2的大小为32的整数倍。

void main(void)
{	
    printf("sizeof(yy2) = %d\n", sizeof(yy2));
    printf("%d\n", sizeof(yy2) % 32); //打印结果为0，说明整个结构体变量的大小为32的整数倍
    
    return 0;
}
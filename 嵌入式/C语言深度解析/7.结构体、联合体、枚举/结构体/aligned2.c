#include <stdio.h>

#pragma pack(1)
struct kk1
{       
    char a;			//1>=1，对齐值为1
    short b;		//2>=1，对齐值为1
    int c;			//4>=1，对齐值为1
    long long d;//8>=1，对齐值为1
}yy1;     
#pragma pack()

//按照1字节对齐，但是最后补了1个字节，所以大小位16
struct kk2
{       
    char a;			//1>=1，对齐值为1
    short b;		//2>=1，对齐值为1
    int c;			//4>=1，对齐值为1
    long long d;//8>=1，对齐值为1
}__attribute__((aligned(1))) yy2;  //等价于__attribute__((packed))

void main(void)
{	
    printf("%d\n", sizeof(struct kk1));//15
    printf("%d\n", sizeof(struct kk2));//16
}
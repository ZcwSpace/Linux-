#include <stdio.h>

struct kk1
{       
    char a;			//1<8，对齐值为1
    short b;		//2<8，对齐值为2
    int c;			//4<8，对齐值为4
    long long d;//8>=8，对齐值为8
}yy1;   //16

#pragma pack(1) //对齐系数为1

struct kk2
{       
    char a;			//1>=1，对齐值为1
    short b;		//2>=1，对齐值为1
    int c;			//4>=1，对齐值为1
    long long d;//8>=1，对齐值为1
}yy2; //15    		//1>=1，对齐值为1

#pragma pack()

#pragma pack(4)

struct kk3
{       
    char a;			//1<4，对齐值为1
    short b;		//2<4，对齐值为2
    int c;			//4>=4，对齐值为4
    long long d;//8>=4，对齐值为4
}yy3;   //16 			

#pragma pack()

int main()
{
    printf("%d\n", sizeof(yy1));
    printf("%d\n", sizeof(yy2));
    printf("%d\n", sizeof(yy3));

    return 0;
}
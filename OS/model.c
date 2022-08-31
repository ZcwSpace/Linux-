#include <stdio.h>
#include <unistd.h>

#define REGS_FOREACH(_) _(X) _(Y)//两个寄存器
#define RUN_LOGIC X1=!X&&Y;\
        Y1=!X&&!Y;
#define DEFINE(X) static int X,X##1;
#define UPDATE(X) X=X##1;
#define PRINT(X) printf(#X "=%d",X);

int main()
{
    REGS_FOREACH(DEFINE);//static int X,X1; static int Y,Y1;;
    while(1)
    {
        RUN_LOGIC;//X1=!X&&Y; Y1=!X&&!Y;;
        REGS_FOREACH(PRINT);//printf("X" "=%d",X); printf("Y" "=%d",Y);;
        REGS_FOREACH(UPDATE);//X=X1; Y=Y1;;
        putchar('\n');
        sleep(1);
    }
}

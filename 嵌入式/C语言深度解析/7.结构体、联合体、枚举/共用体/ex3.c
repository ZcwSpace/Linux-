//include "stdafx.h" //这个是VC++特有的头文件，在codeblocks下不需要
#include <stdio.h>

enum Week 
{
    SUM,
    MON,
    TUE,
    WEN,
    THU,
    FRI,
    SAT,
};

void fun(enum Week weekday)
{
    printf("今天是周%d\n", weekday);
}

int main(void)
{	
    fun(WEN);
    fun(100);	

    return 0;
}
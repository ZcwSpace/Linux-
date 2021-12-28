//进程终止处理函数
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void process_deal1(void);
void process_deal2(void);
void fun1(void);
void fun2(void);

int main()
{
    atexit(process_deal1);
    //atexit(process_deal2);//先把函数地址入栈，等进程终止时再取出依次调用
    fun1();
    fun2();
    printf("Hello\n");
//异常终止不调用
/*
    while(1)
    {

    }
*/
    //_exit(0);//也不调用
   
    return 0;
}
void process_deal1(void)
{
    printf("save list\n");
}
void process_deal2(void)
{
    printf("deal 2\n");
}
void fun1(void)
{
    exit(-1);
}
void fun2(void)
{
    //exit(-1);
}
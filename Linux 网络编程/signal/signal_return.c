#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include<unistd.h>

void signal_catch(int signal_index);
void process_exit_deal(void);

int main(void)
{
    __sighandler_t signal_return=NULL;

    //atexit(process_exit_deal);
    //signal_return=signal(SIGINT,SIG_IGN);//ctrl+c被忽略
    //signal_return=signal(SIGINT,SIG_DFL);//对ctrl+c的处理变为默认处理方式
    signal_return=signal(SIGINT,signal_catch);
    //signal_return=signal(SIGINT,SIG_DFL);
    printf("hello");

/*
    if(signal_return==SIG_ERR)
    {
        perror("set fail");
    }
    else if(signal_return==SIG_IGN)
    {
        printf("neglect\n");
    }
    else if(signal_return==SIG_DFL)
    {
        printf("default\n");
    }
    else 
    {
        printf("capture %p\n",signal_return);
    }
*/
    while(1);

    return 0;
}
void signal_catch(int signal_index)
{
    printf("捕获函数提前终止！");
    //fflush(stdout);
    //return;

    switch (signal_index)
    {
    case 2:printf("SIGINT_signal_index=%d",signal_index);break;
    case 3:printf("SIGQUIT_signal_index=%d\n",signal_index);break;
    default:printf("暂未编写此种捕获处理方式！");break;
    }
    //正常终止
    //exit (-1);
}
void process_exit_deal(void)
{
    printf("precess over");
    printf("save list to file");
}

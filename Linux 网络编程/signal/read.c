#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include<unistd.h>

void signal_catch(int signal_index);

int main(void)
{
    char buf[100]={0};

    signal(SIGINT,signal_catch);
    read(0,buf,sizeof(buf)-1);
    printf("Hello\n");

/*
    signal(SIGINT,SIG_IGN);//ctrl+c被忽略
    signal(SIGINT,SIG_DFL);//对ctrl+c的处理变为默认处理方式
    signal(SIGINT,signal_catch);

    signal(SIGQUIT,SIG_IGN);
    signal(SIGQUIT,SIG_DFL);
    signal(SIGQUIT,signal_catch);

    while(1);
*/
    return 0;
}
void signal_catch(int signal_index)
{
    switch (signal_index)
    {
    case 2:printf("SIGINT_signal_index=%d\n",signal_index);break;
    case 3:printf("SIGQUIT_signal_index=%d\n",signal_index);break;
    default:printf("暂未编写此种捕获处理方式！");break;
    }
}
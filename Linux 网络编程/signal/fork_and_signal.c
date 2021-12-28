#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void signal_catch(int signal_index);

int main(void)
{
    pid_t ret;

    //signal(SIGINT,SIG_IGN);
    //signal(SIGINT,signal_catch);
    //signal(SIGINT,SIG_DFL);

    ret=fork();
    if(ret>0)
    {
        signal(SIGINT,signal_catch);
    }
    else if(ret==0)
    {
        signal(SIGINT,signal_catch);
    }
    while(1);
    
    return 0;
}
void signal_catch(int signal_index)
{
    printf("pid=%d,signal=%d\n",getpid(),signal_index);
}
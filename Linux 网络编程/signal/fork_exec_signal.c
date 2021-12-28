#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void signal_catch(int signal_index);

int main(int argc,char**argv,char**environ)
{
    pid_t ret;

    //signal(SIGINT,SIG_IGN);
    signal(SIGINT,signal_catch);
    //signal(SIGINT,SIG_DFL);

    ret=fork();
    if(ret>0)
    {
        
    }
    else if(ret==0)
    {
        execve("./new_pro",argv,environ);
    }
    while(1);
    
    return 0;
}
void signal_catch(int signal_index)
{
    printf("parent pid=%d,signal=%d\n",getpid(),signal_index);
}
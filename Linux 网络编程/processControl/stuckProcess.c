#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t ret;
//子进程是僵尸进程：子进程死了，父进程一直活着
//子进程是孤儿进程：父进程死了，子进程一直活着
    ret=fork();
    if(ret>0)
    {
        printf("%d\n",getpid());
        //while(1);
        
    }
    else if(ret==0)
    {
        
        printf("%d\n",getpid());
        //return 0;
        while(1);
    }
    //ps:r 正在运行 s休眠状态 z僵尸进程

    //return 0;
    exit(-1);
}
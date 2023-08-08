#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <unistd.h>
int main(void)
{
int fork_ret;
    fork_ret=fork();
if(fork_ret>0)
    {
//得到第二个子进程
        fork_ret=fork();
if(fork_ret>0)
        {
//父进程执行的代码
while(1)
            {
                printf("000000\n");
                sleep(1);
            }
        }
else if(fork_ret==0)
        {
//第二个子进程执行的代码
while(1)
            {
                printf("222222\n");
                sleep(1);
            }
        }
    }
//得到第一个子进程
else if(fork_ret==0)
    {
//第一个子进程执行的代码
while(1)
        {
            printf("111111\n");
            sleep(1);
        }
    }
return 0;
}
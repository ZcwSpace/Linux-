#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char ** environ;

int main(int argc,char** argv)
{
    pid_t ret;
    int fd=0;

    ret=fork();
    if(ret>0)
    {
        sleep(1);
    }
    else if(ret==0)
    {
        char *my_argv[]={"mds","erc"};
        char *my_env[]={"AA=aaa","BB=bb"};
        //int execve(const char *filename, char *const argv[],char *const envp[]);// 新文件名 参数 环境变量表
        execve("newProcess",my_argv,my_env);
    }
    
    return 0;
}
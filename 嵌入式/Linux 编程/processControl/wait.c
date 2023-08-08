#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>

int main(int argc,char** argv,char ** environ)
{
    pid_t p;
    int ret;
    //wait:主动获取子进程的进程终止状态，主动回收子进程终止后占用的资源。
    //进程终止状态：终止原因（正常终止）<<8|推出状态的低8位
    //进程终止状态=是否产生core文件位|终止原因（异常终止）<<8|终止该进程的信号编号
    ret=fork();
    if(ret>0)
    {
        int status=0;
        p=wait(&status);
        printf("status=%d\n",status);
        if(WIFEXITED(status))//为0不是正常终止的
        {
            printf("existed:%d\n",WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status))//为0不是异常终止的
        {
            printf("signaled killed %d\n",WTERMSIG(status));
        }
    }
    else if(ret==0)
    {
        //int execve(const char *filename, char *const argv[],char *const envp[]);// 新文件名 参数 环境变量表
        execve("newProcess",argv,environ);
    }
    
    return 1000;//退出状态
}
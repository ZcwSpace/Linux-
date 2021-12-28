#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(void)
{
    pid_t pid,ppid;
    uid_t uid;
    gid_t gid;

    pid=getpid();
    ppid=getppid();//第一个p：parent第二个t：process
    uid=getuid();
    gid=getgid();

    printf("当前进程的ID=%d\n",pid);
    printf("当前进程父进程的ID=%d\n",ppid);
    printf("调用该函数进程的用户ID=%d\n",uid);
    printf("调用该函数进程的组ID=%d\n",gid);
    while(1)
    {

    }

    return 0;
}
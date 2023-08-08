#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t ret;

    printf("before fork()");//不加\n，子进程会复制父进程的数据空间
    ret=fork();
   

    if(ret>0)
    {
        printf("parent PID=%d\n",getpid());
        printf("parent ret=%d\n",ret);
    }
    else if(ret==0)
    {
        printf("child PID=%d\n",getpid());
        printf("child ret=%d\n",ret);
        //while(1);
        sleep(2);
    }
    
    //printf("%d,fork()的返回值为：%d\n",getpid(),ret);//父进程返回紫禁城id，子进程返回0
     //printf("after fork()\n\n");
    while(1)
    {

    }

    return 0;
}
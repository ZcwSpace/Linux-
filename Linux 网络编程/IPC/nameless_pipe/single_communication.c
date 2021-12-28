#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<strings.h>
#include<signal.h>

void signal_catch(int signal_index);

int main(void)
{
    pid_t fork_ret;
    int pipefd[2];//0：读描述符,1：写描述符
    int pipe_ret;

    //父进程在fork之前，先调用pipe创建无名管道，并获取读、写文件描述符
    pipe_ret=pipe(pipefd);
    if(pipe_ret==-1)
    {
        perror("pipe faild");
    }
    //printf("0 %d,1 %d\n",pipefd[0],pipefd[1]);0 3,1 4 测试文件描述符的值
    //fork创建出子进程后，子进程继承无名管道的读、写描述符
    fork_ret=fork();

    //父子进程使用各自管道的读、写文件描述符进行读、写操作，即可实现通信
    if(fork_ret>0)
    {
        signal(SIGPIPE,signal_catch);
        //一般来说不用的文件描述符要被关闭
        //close(pipefd[0]);
        while(1)
        {
            write(pipefd[1],"hello\n",6);
            sleep(1);
        }
    }
    else if(fork_ret==0)
    {
        //char *buf;
        char buf[30]={0};

        close(pipefd[0]);
        close(pipefd[1]);

        while(1)
        {
            bzero(buf,sizeof(buf));
            //读管道时，如果没有数据的话，读操作会休眠（阻塞）。
            read(pipefd[0],buf,sizeof(buf));
            //printf("child:recv data:%s\n",buf);
        }
    }
    
    return 0;
}
void signal_catch(int signal_index)
{
    if(signal_index==13)
    {
        printf("SIGPIPE\n");
    }
    
}
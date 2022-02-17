#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <poll.h>
#include <signal.h>

void print_err(char *str,int line,int err_no);
void signal_catch(int signal_index);

int mousefd,read_ret;

int main(void)
{
    char key_buf[100]={0};
    int flag;

    mousefd=open("/dev/input/mouse3",O_RDONLY);
    if(mousefd==1)
    {
        print_err("open mouse fial",__LINE__-3,errno);
    }

    //1.调用signal函数对SIGIO信号设置捕获函数
    signal(SIGIO,signal_catch);
    //2.使用fcntl函数，将接收SIGIO信号的进程设置为当前进程
    fcntl(mousefd,F_SETOWN,getpid());


    //3.使用fcntl函数，对文件描述符增设O_ASYNC的状态标志，让fd支持异步
    flag=fcntl(mousefd,F_GETFL);
    flag|=O_ASYNC;//补充设置P_SAYNC
    fcntl(mousefd,F_SETFL,flag);

    while (1)
    {
        bzero(key_buf,sizeof(key_buf));
        read_ret=read(0,key_buf,sizeof(key_buf));
        if(read_ret>0)
        {
            printf("%s\n",key_buf);
        }
    }
    
    
    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}
void signal_catch(int signal_index)
{
    long mouse_buf;    

    if(signal_index==SIGIO)
    {
        read_ret=read(mousefd,&mouse_buf,sizeof(mouse_buf));
        if(read_ret>0)
        {
            printf("%ld\n",mouse_buf);
        }
    }
}
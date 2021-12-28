#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>

#define  PATHNAME "./single_fifo"
int receive_fifo(char *path_NAME,int mode);
void signal_catch(int signal_index);

int main(void)
{
    receive_fifo(PATHNAME,O_RDONLY);

    return 0;
}
int receive_fifo(char *path_name,int mode)
{
    int ret,fd;
    char buf[100]={0};

    signal(SIGINT,signal_catch);

    ret=mkfifo(path_name,0664);
    if(ret==-1&& errno!=EEXIST)//忽略有名管道文件已存在的错误
    {
        perror("mkfifo fail");
    }

    fd=open(path_name,mode);
    if(fd==-1)
    {
        printf("open fail");
    }

    while(1)
    {
        bzero(buf,sizeof(buf));
        read(fd,buf,sizeof(buf));
        printf("receive:%s\n",buf);
    }
    return fd;
}
void signal_catch(int signal_index)
{
    remove(PATHNAME);
    exit(-1);
}



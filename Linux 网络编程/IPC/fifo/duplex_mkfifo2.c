#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>

#define  PATHNAME "./duplex_fifo"
#define  PATHNAME2 "./duplex2_fifo"
int create_fifo(char *path_name,int mode);
void signal_catch(int signal_index);

int main(void)
{
    char buf[100]={0};
    int fd_w,fd_r;
    int ret;

    fd_r=create_fifo(PATHNAME,O_RDONLY);
    fd_w=create_fifo(PATHNAME2,O_WRONLY);

    ret=fork();
    if(ret>0)
    {
        signal(SIGINT,signal_catch);
        while(1)
        {
            bzero(buf,sizeof(buf));
            scanf("%s",buf);
            write(fd_w,buf,sizeof(buf));
        }
    }
    else if(ret==0)
    {
        while(1)
        {
            bzero(buf,sizeof(buf));
            read(fd_r,buf,sizeof(buf));
            printf("2_c_r=%s\n",buf);
        }
    }

    return 0;
}
int create_fifo(char *path_name,int mode)
{
    int ret,fd;

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
    return fd;
}
void signal_catch(int signal_index)
{
    remove(PATHNAME);
    remove(PATHNAME2);
    exit(-1);
}



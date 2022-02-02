#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<signal.h>
#include <sys/types.h>
#include <unistd.h>
#include<pthread.h>

//出错处理函数
void print_err(char *str,int line,int err_no);
void read_key();
void read_mouse();
void read_file();
void * pthread1(void *);
void read_key_and_mouse();

int main(void)
{
    int fork_ret;
    pthread_t td;
    
    //read_mouse();
    //read_key();
    /*进程
    fork_ret=fork();
    if(fork_ret>0)
    {
        read_mouse();
    }
    else if(fork_ret==0)
    {
        read_key();
    }
    */
   /*线程
   pthread_create(&td,NULL,pthread1,NULL);
   read_mouse();*/
   read_key_and_mouse();

    return 0;
}
void print_err(char *str,int line,int err_no)
{
    printf("%d,%s:%s\n",line,str,strerror(err_no));

    exit(-1);
}
void read_key()
{
    char buf[100]={0};
    int read_ret=0,flag;

    //重设
    //fcntl(0,F_SETFL,O_RDONLY|O_NONBLOCK);
    //补设
    flag=fcntl(0,F_GETFL);//返回原有文件状态标志
    flag |=O_NONBLOCK;//通过|操作，在已有的标志上增加O_NONBLOCK
    fcntl(0,F_SETFL,flag);//设置修改后的“文件状态标志”

    while(1)
    {
       // printf("111\n");
        //read返回读到的字节数
        read_ret=read(0,buf,sizeof(buf));
        if(read_ret>0)
        {
            printf("%s",buf);
        }
       // printf("222\n\n"); 
        //sleep(1);
    }       
}
void read_mouse()
{
    int mousefd=-1;
    int mouse_addr;
    int read_ret;

    mousefd=open("/dev/input/mouse3",O_RDONLY);
    if(mousefd==-1)
    {
        print_err("open mouse fail",__LINE__-3,errno);
    }
    while (1)
    {
        printf("111\n");
        //read返回读到的字节数
        read_ret=read(mousefd,&mouse_addr,sizeof(mouse_addr));
        if(read_ret>0)
        {
            printf("%d\n",mouse_addr);
        }
        printf("222\n\n"); 
    }
    
}

void read_file()
{
    int fd,read_ret;
    char *buf;

    fd=open("./file",O_RDONLY|O_CREAT,0664);
    if(fd==-1)
    {
        print_err("open ./file fail",__LINE__-3,errno);
    }

    while(1)
    {
        printf("111\n");
        //read返回读到的字节数
        read_ret=read(fd,buf,100);
        printf("read_ret=%d\n",read_ret);

        if(read_ret>0)
        {
            printf("%d\n",buf);
        }
        printf("222\n\n"); 
    }
}

void *pthread1(void * arg)
{
    read_key();
}

void read_key_and_mouse()
{
    int mousefd=-1,flag;
    int mouse_addr;
    int read_ret;
    char buf[100]={0};

    mousefd=open("/dev/input/mouse3",O_RDONLY);
    if(mousefd==-1)
    {
        print_err("open mouse fail",__LINE__-3,errno);
    }

    flag=fcntl(0,F_GETFL);//返回原有文件状态标志
    flag |=O_NONBLOCK;//通过|操作，在已有的标志上增加O_NONBLOCK
    fcntl(0,F_SETFL,flag);//设置修改后的“文件状态标志”

    flag=fcntl(mousefd,F_GETFL);//返回原有文件状态标志
    flag |=O_NONBLOCK;//通过|操作，在已有的标志上增加O_NONBLOCK
    fcntl(mousefd,F_SETFL,flag);//设置修改后的“文件状态标志”

    while (1)
    {
        printf("111\n");
        
        //read返回读到的字节数
        
        read_ret=read(mousefd,&mouse_addr,sizeof(mouse_addr));
        if(read_ret>0)
        {
            printf("%d\n",mouse_addr);
        }
        read_ret=read(0,buf,sizeof(buf));
        if(read_ret>0)
        {
            printf("%s",buf);
        }
        printf("222\n\n");
        sleep(1);
    }

}
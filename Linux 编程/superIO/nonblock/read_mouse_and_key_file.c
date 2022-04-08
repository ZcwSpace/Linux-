#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<errno.h>
//出错处理函数
void print_err(char *str,int line,int err_no);
void read_key();
void read_mouse();
void read_file();

int main(void)
{
    read_mouse();

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
    int read_ret=0;

    while(1)
    {
        printf("111\n");
        //read返回读到的字节数
        read_ret=read(0,buf,sizeof(buf));
        if(read_ret>0)
        {
            printf("%s",buf);
        }
        printf("222\n\n"); 
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
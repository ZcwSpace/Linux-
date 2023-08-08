#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "file_lock.h"

void print_err(char *str,int line,int err_no);

int main(void)
{
    int fd=0,ret=0;

    //创建或打开要写入的文件
    fd=open("./file.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd==1)
    {
        print_err("open fial",__LINE__-3,errno);
    }

    //创建子进程
    ret=fork();
    if(ret>0)
    {
        while(1)
        {
            B_W(fd,SEEK_SET,0,0);
            write(fd,"hello ",6);
            write(fd,"world\n",6);
            UN_LOCK(fd,SEEK_SET,0,0);
        }
    }
    else if(ret==0)
    {
        while(1)
        {
            B_W(fd,SEEK_SET,0,0);
            write(fd,"hello ",6);
            write(fd,"world\n",6);
            UN_LOCK(fd,SEEK_SET,0,0);
        }
    }
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  
}
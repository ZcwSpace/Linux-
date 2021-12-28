#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

void my_err(const char * err_string,int line);

void my_err(const char * err_string,int line)
{
    fprintf(stderr,"line:%d",line);//stderr:标准输出文件
    perror(err_string);
    exit(1);
}

int main()
{
    int ret;
    int access_mode;
    int fd;

    if((fd=open("example_64",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU))==-1)
    {
        my_err("open",__LINE__);
    }

    if((ret=fcntl(fd,F_SETFL,O_APPEND))<0)
    {
        my_err("fcntl",__LINE__);
    }

    if((ret=fcntl(fd,F_GETFL,0))<0)
    {
        my_err("fcntl",__LINE__);
    }
    
    access_mode=ret&O_ACCMODE;//O_ACCMODE:000011 O_EDONLY:000000 O_WRONLY:000001 O_RDWR:000002
    printf("acccess_mode=%o\n",access_mode);
    printf("ret=%o\n",ret);
    if(access_mode==O_RDONLY)
    {
        printf("example_64 access mode:read only");
    }
    else if(access_mode==O_WRONLY)
    {
        printf("example_64 access mode:write only");
    }
    else if(access_mode==O_RDWR)
    {
        printf("example_64 access mode:read+write");
    }
    if(ret&O_APPEND)
    {
        printf(",append");
    }
    if(ret&O_NONBLOCK)//O_NONBLOCK:以非阻塞的方式打开文件，对于open及随后对该文件的操作，都会立即返回
    {
        printf(",nonblock");
    }
    if(ret&O_SYNC)//O_SYNC：以同步的方式打开文件，任何对文件的修改都会阻塞直到物理磁盘上的数据同步以后才返回
    {
        printf(",sync");
    }
    printf("\n");
    printf("ret&O_APPEND=%d\n",ret&O_APPEND);
    printf("ret&O_NONBLOCK=%d\n",ret&O_NONBLOCK);
    printf("ret&O_SYNC=%d\n",ret&O_SYNC);
    
    return 0;
}
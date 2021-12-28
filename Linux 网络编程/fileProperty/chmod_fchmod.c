#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char** argv)
{
    if(argc!=2)
    {
        printf("输入错误！");
    }
    int ret;
    //ret=chmod(argv[1],0777);
    int fd;

    fd=open(argv[1],O_RDWR);
    if(fd==-1)
    {
        perror("open fail");
        exit(-1);
    }
    ret=fchmod(fd,0444);
    if(ret==-1)
    {
        perror("chmod fail");
        exit(-1);
    }   
    //int fchmod(int fd, mode_t mode);

    return 0;
}
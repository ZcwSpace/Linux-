#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char** argv)
{
    int ret;

    if(argc!=2)
    {
        printf("输入错误!\n");
        exit(-1);
    }

    ret=mkdir(argv[1],0775);
    if(ret==-1)
    {
        perror("mkdir error");
        exit(-1);
    }

    return 0;
}


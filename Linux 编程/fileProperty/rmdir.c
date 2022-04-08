#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char** argv)
{
    int ret;
    if(argc!=2)
    {
        printf("输入错误!\n");
        exit(-1);
    }
    ret=rmdir(argv[1]);
    if(ret==-1)
    {
        perror("rmdir error");
        exit(-1);
    }

    return 0;
}
    

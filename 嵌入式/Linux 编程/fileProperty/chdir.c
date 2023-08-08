#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char** argv)
{
    if(argc!=2)
    {
        printf("输入错误！");
    }
    char buf[100]={0};
    int fd;

    getcwd(buf,99);
    printf("修改前路径：%s\n",buf);

    fd=chdir(argv[1]);
    if(fd==-1)
    {
        perror("chdir error");
        exit(-1);
    }

    getcwd(buf,99);
    printf("修改后路径：%s\n",buf);

    return 0;
}
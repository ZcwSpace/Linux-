#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<error.h>

void my_err(const char*error_string,int line);
int my_read(int fd);

int main(int argc,char **argv)
{
    int fd;
    char write_buf[32]="Hello World!";

    //if((fd=creat("example_63.c",S_IRWXU))==-1)
    if((fd=open("example_63.c",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU))==-1)
    {
        my_err("open",__LINE__);//_LINE_是预编译器内置宏，表示行数
    }
    else
    {
        printf("creat file success\n");
    }

    if(write(fd,write_buf,strlen(write_buf))!=strlen(write_buf))//write返回写入字节数
    {
        my_err("write",__LINE__);
    }
    my_read(fd);

    printf("/*--------------------*/\n");
    if(lseek(fd,10,SEEK_CUR)==-1)
    {
        my_err("lseek",__LINE__);
    }
    if(write(fd,write_buf,strlen(write_buf))!=strlen(write_buf))
    {
        my_err("write",__LINE__);
    }
    my_read(fd);
    
    close(fd);
    return 0;
}
void my_err(const char*error_string,int line)
{
    fprintf(stderr,"line:%d",line);//stderr:标准输出文件
    perror(error_string);
    exit(1);
}
int my_read(int fd)
{
    int len;
    int ret;
    int i;
    char read_buf[64];

    if(lseek(fd,0,SEEK_END)==-1)
    {
        my_err("lseek",__LINE__);
    }
    if((len=lseek(fd,0,SEEK_CUR))==-1)
    {
        my_err("lseek",__LINE__);
    }
    if(lseek(fd,0,SEEK_SET)==-1)
    {
        my_err("lseek",__LINE__);
    }

    printf("len:%d\n",len);
    if((ret=read(fd,read_buf,len))<0)
    {
        my_err("read",__LINE__);
    }

    for(i=0;i<len;i++)
    {
        printf("%c",read_buf[i]);
    }
    printf("\n");

    return ret;
}
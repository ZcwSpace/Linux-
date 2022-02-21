#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define DATA_LENGTH 819200

void print_err(char *str,int line,int err_no);

int main(void)
{
    int read_fd,write_fd;
    void *read_addr=NULL,*write_addr=NULL;
    struct stat *__buf;
    
    //打开要进行读写操作的文件
    read_fd=open("./A.txt",O_RDWR);
    if(read_fd==-1)
    {
        print_err("open A.txt failed",__LINE__-3,errno);
    }

    write_fd=open("./B.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(write_fd==-1)
    {
        print_err("open B.txt failed",__LINE__-3,errno);
    }
    
    //分别调用mmap映射上文创建的文件
    //fstat(read_fd,__buf);
    read_addr=mmap(NULL,DATA_LENGTH,PROT_READ,MAP_SHARED,read_fd,0);
    if(read_addr==(void *)-1)
    {
        print_err("mmap A.txt failed",__LINE__-3,errno);
    }
    truncate("./B.txt",DATA_LENGTH);
    write_addr=mmap(NULL,DATA_LENGTH,PROT_WRITE,MAP_SHARED,write_fd,0);
    if(write_addr==(void *)-1)
    {
        print_err("mmap B.txt failed",__LINE__-3,errno);
    }
    
    //copy A.txt B.txt
    memcpy(write_addr,read_addr,DATA_LENGTH);

    //取消映射且关闭文件
    munmap(read_addr,DATA_LENGTH);
    munmap(write_addr,DATA_LENGTH);
    close(read_fd);
    close(write_fd);

    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}
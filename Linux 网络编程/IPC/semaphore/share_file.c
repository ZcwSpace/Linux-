#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void print_err(char* str);

int main(void)
{
    pid_t ret=0;
    int fd=0;

    fd=open("./file.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd==-1)
    {
        print_err("open fail");
    }
    ret=fork();
    if(ret>0)
    {
        while(1)
        {
            write(fd,"hello ",6);
            write(fd,"world\n",6);
            
        }
    }
    else if(ret==0)
    {
        while(1)
        {
            write(fd,"good  ",6);
            write(fd,"bye  \n",6);
        }
    }

}
void print_err(char* str)
{
    perror(str);
    exit(-1);
}
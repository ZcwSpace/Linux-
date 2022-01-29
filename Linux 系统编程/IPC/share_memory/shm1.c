#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>

#define FILE_NAME "./shm_file"
#define SHM_SIZE 4096
#define  PATHNAME "./duplex_fifo"

void get_shm();
void print_err(char *string);
void signal_catch(int signal_index);
int create_fifo(char *path_name,int mode);

int shm_id=-1;
char buf[300]={"121448948944165489864156418941564189613255512389962165864841465\n"};
void *shmaddr=NULL;

int main(void)
{
    int fd;
    int ret;
    pid_t pid;

    signal(SIGINT,signal_catch);
    fd=create_fifo(PATHNAME,O_RDONLY);
    
    read(fd,&pid,8);
    get_shm();
    shmaddr=shmat(shm_id,NULL,0);
    if(shmaddr==(void *)-1)
    {
        print_err("shmat fail");
    }

    while(1)
    {
        /*memcpy指的是C和C++使用的内存拷贝函数，函数原型为void *memcpy(void *destin, void *source, unsigned n)；
        函数的功能是从源内存地址的起始位置开始拷贝若干个字节到目标内存地址中，即从源source中拷贝n个字节到目标destin中。*/
        //void *memcpy(void *dest, const void *src, size_t n);
        memcpy(shmaddr,buf,sizeof(buf));
        kill(pid,SIGUSR1);
        sleep(1);
    }

    return 0;
}
void get_shm()
{
    int fd,ret;
    key_t key;

    fd=open(FILE_NAME,O_CREAT|O_RDWR,0664);
    if(fd==-1)
    {
        print_err("open fail");
    }
    key=ftok(FILE_NAME,'b');
    if(key==-1)
    {
        print_err("ftok fail");
    }
    shm_id=shmget(key,SHM_SIZE,0664|IPC_CREAT);
    if(shm_id==-1)
    {
        print_err("shmget fail");
    }
}
void print_err(char *string)
{
    perror(string);
    exit(-1);
}
int create_fifo(char *path_name,int mode)
{
    int ret,fd;

    ret=mkfifo(path_name,0664);
    if(ret==-1&& errno!=EEXIST)//忽略有名管道文件已存在的错误
    {
        perror("mkfifo fail");
    }

    fd=open(path_name,mode);
    if(fd==-1)
    {
        printf("open fail");
    }
    return fd;
}
void signal_catch(int signal_index)
{
    
    shmdt(shmaddr);
    shmctl(shm_id,IPC_RMID,NULL);
    remove(FILE_NAME);
    remove(PATHNAME);
    exit(-1);
}
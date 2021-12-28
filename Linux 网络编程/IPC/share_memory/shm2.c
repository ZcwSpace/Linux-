#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include<signal.h>
#include<errno.h>
#include<unistd.h>

#define FILE_NAME "./shm_file"
#define SHM_SIZE 4096
#define  PATHNAME "./duplex_fifo"

void get_shm();
void print_err(char *string);
void signal_catch(int signal_index);
int create_fifo(char *path_name,int mode);

int shm_id=-1;
char buf[300]={"121448948944165489864156418941564189613255512389962165864841465"};
 void *shmaddr=NULL;

int main(void)
{
    char buf[100]={0};
    int fd_w;
    pid_t pid;
    
    
    signal(SIGINT,signal_catch);
    signal(SIGUSR1,signal_catch);
    fd_w=create_fifo(PATHNAME,O_WRONLY);
    pid=getpid();
    write(fd_w,&pid,8);
    get_shm();
    shmaddr=shmat(shm_id,NULL,0);
    if(shmaddr==(void *)-1)
    {
        print_err("shmat fail");
    }

    while(1)
    {
        pause();
        printf("%s",(char *)shmaddr);
        bzero(shmaddr,SHM_SIZE);
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
void signal_catch(int signal_index)
{
    if(signal_index==2)
    {
        shmdt(shmaddr);
        shmctl(shm_id,IPC_RMID,NULL);
        remove(FILE_NAME);
        remove(PATHNAME);
        exit(-1);
    }
    else if(signal_index==10)
    {
        
    }
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
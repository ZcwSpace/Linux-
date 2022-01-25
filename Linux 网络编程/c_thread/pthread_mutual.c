#include <stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include<unistd.h>

//声明次线程数量
sem_t sem[1]={1};

#define SECON_PTH_NUMS 1

void print_err(char *str,int line,int err_no);
void *child_pthread(void *pth_arg);
void signal_catch(int signal_index);

typedef struct ptharg
{
    pthread_t tid;
}ptharg;
struct globle_va
{
    ptharg pthread_arg[1];
    int fd;
}glbva;


int main(void)
{
    signal(SIGINT,signal_catch);
    //初始化信号量
    sem_init(&sem[0],0,1);
    //创建要写入的文件
    glbva.fd=open("./test.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    //创建子线程
    for(int i=0;i<SECON_PTH_NUMS;i++)
    {
        glbva.pthread_arg[i].tid=pthread_create(&glbva.pthread_arg[i].tid,NULL,child_pthread,NULL);
    }
    //循环写入数据
    while(1)
    {
        sem_wait(&sem[0]);
        write(glbva.fd,"hello ",6);
        write(glbva.fd,"world\n",6);
        sem_post(&sem[0]);
    }
}
void print_err(char *str,int line,int err_no)
{
    printf("%d,%s,%s",line,str,strerror(err_no));
}
void *child_pthread(void *pth_arg)
{
    while(1)
    {
        sem_wait(&sem[0]);
        write(glbva.fd,"hello ",6);
        write(glbva.fd,"world\n",6);
        sem_post(&sem[0]);
    }
}
void signal_catch(int signal_index)
{
    pthread_exit(&glbva.pthread_arg[0].tid);
    close(glbva.fd);
    sem_destroy(&sem[0]);

    exit(1);
}
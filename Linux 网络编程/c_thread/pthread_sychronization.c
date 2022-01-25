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

//声明次线程数量、信号量数量
#define SECON_PTH_NUMS 2
#define SEM_NUMS 3

sem_t sem[SEM_NUMS];

//声明函数
void print_err(char *str,int line,int err_no);
void *child_pthread1(void *pth_arg);
void *child_pthread2(void *pth_arg);
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
    sem_init(&sem[1],0,0);
    sem_init(&sem[2],0,0);
    //创建要写入的文件
    glbva.fd=open("./test.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    //创建子线程
    glbva.pthread_arg[0].tid=pthread_create(&glbva.pthread_arg[0].tid,NULL,child_pthread1,NULL);
    glbva.pthread_arg[1].tid=pthread_create(&glbva.pthread_arg[1].tid,NULL,child_pthread2,NULL);
    
    //循环写入数据
    while(1)
    {
        sem_wait(&sem[0]);
        write(glbva.fd,"1111\n",5);
        sem_post(&sem[1]);
    }
}
void print_err(char *str,int line,int err_no)
{
    printf("%d,%s,%s",line,str,strerror(err_no));
}
void *child_pthread1(void *pth_arg)
{
    while(1)
    {
        sem_wait(&sem[1]);
        write(glbva.fd,"2222\n",5);
        sem_post(&sem[2]);
    }
}
void *child_pthread2(void *pth_arg)
{
    while(1)
    {
        sem_wait(&sem[2]);
        write(glbva.fd,"3333\n",5);
        sem_post(&sem[0]);
    }
}
void signal_catch(int signal_index)
{
    pthread_exit(&glbva.pthread_arg[0].tid);
     pthread_exit(&glbva.pthread_arg[1].tid);
    close(glbva.fd);
    for(int i=0;i<SEM_NUMS;i++)
    {
        sem_destroy(&sem[i]);
    }
    
    exit(1);
}
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<signal.h>

//线程函数
void *pth_fun(void *pth_arg);
void signal_catch(int signal_index);
void process_exit_deal(void );
void thread_exit_deal(void *arg);

//
typedef struct
{
    pthread_t tid;
}pth_unit;
pth_unit pth; 

int main(void)
{
    
    signal(SIGINT,signal_catch);
    signal(SIGALRM,signal_catch);
    //注册进程退出处理函数,exit正常终止时弹栈调用
    atexit(process_exit_deal);
    pthread_create(&pth.tid,NULL,pth_fun,NULL);
    while (1)
    {
        printf("2222\n");
        sleep(3);
    }
    return 0;
}
void *pth_fun(void *pth_arg)
{
    
    //注册线程退出处理函数
    pthread_cleanup_push(thread_exit_deal,NULL);
    pthread_cancel(pth.tid);
    alarm(3);
    while(1)
    {
        printf("1111\n");
        sleep(1);
    }
    pthread_cleanup_pop(-1);
    return NULL;
}
void signal_catch(int signal_index)
{
    if(signal_index==SIGALRM)
    {
        pthread_cancel(pth.tid);
    }
    else
    {
        exit(0);
    }
}
void process_exit_deal(void)
{
    printf("\nprocessing...\n");
}
void thread_exit_deal(void *arg)
{
    printf("\npthread %lu exit\n",pth.tid);
}
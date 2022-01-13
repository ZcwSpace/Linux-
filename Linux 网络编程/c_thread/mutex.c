#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<errno.h>
#include<string.h>
#include<signal.h>

//线程函数
void *pth_fun(void *pth_arg);
//出错处理函数
void print_error(char *str,int line,int err_no);
//中断处理函数
void signal_catch(int signal_index);

//1、定义互斥锁
pthread_mutex_t mutex;
//定义次线程的线程号
pthread_t t_id;

int main(void)
{
    int mutex_init_ret;
    pthread_t main_tid=pthread_self();

    signal(SIGINT,signal_catch);
    //2、初始化互斥锁
    mutex_init_ret=pthread_mutex_init(&mutex,NULL);
    if(mutex_init_ret!=0)
    {
        printf("pthread_mutex_init fail",__LINE__,errno);
    }
    //创建次线程
    pthread_create(&t_id,NULL,pth_fun,NULL);

    while (1)
    {
        //3、加锁/解锁
        pthread_mutex_lock(&mutex);
        printf("main\n");
        printf("thread\n");
        pthread_mutex_unlock(&mutex);
    }
    

    return 0;
}
void *pth_fun(void *pth_arg)
{
    while(1)
    {
        //3、加锁/解锁
        pthread_mutex_lock(&mutex);
        printf("child\n");
        printf("thread\n");
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}
void print_error(char *str,int line,int err_no)
{
    printf("%d, %s:%s",line,str,strerror(err_no));

    exit(-1);
}
void signal_catch(int signal_index)
{
    if(signal_index==SIGINT)
    {
        pthread_mutex_destroy(&mutex);
        exit(0);
    }
}
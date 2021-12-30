#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

//线程函数
void *pth_fun(void *pth_arg);
void signal_catch(int signal_index);

//次线程信息
typedef struct pthread_arg
{
    pthread_t tid;//线程号
    int phono;//我自己定义的编号
    int fd;//文件描述符
}ptharg; 
ptharg pth;
int main(void)
{
    //用普通函数来单线运行
    //pth_fun(NULL);

    //用线程函数来并发运行
    /*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/
    pthread_create(&pth.tid,NULL,pth_fun,NULL);
    
    //获取当前函数的线程号，并结束当前线程的运行
    //int pthread_cancel(pthread_t thread);
    //pthread_cancel(pthread_self());
    pthread_exit(NULL);
    //定时5秒，时间到了取消次线
    signal(SIGALRM,signal_catch);
    alarm(5);
    //return 0;
    while (1)
    {
        printf("2222\n");
        sleep(2);
    }
    

    return 0;
}
void *pth_fun(void *pth_arg)
{
    int i=1;
    while(1)
    {
        printf("%d\n",i);
        i++;
        sleep(1);
    }

    return NULL;
}
void signal_catch(int signal_index)
{
    if(signal_index==SIGALRM)
    {
        //取消线程
        pthread_cancel(pth.tid);
    }
}
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

//线程函数
void *pth_fun(void *pth_arg);
void signal_catch(int signal_index);

//线程编号
pthread_t t_id=0;

int main(void)
{
    //用普通函数来单线运行
    //pth_fun(NULL);

    //用线程函数来并发运行
    /*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/
    pthread_create(&t_id,NULL,pth_fun,NULL);

    //定时5秒，时间到了取消次线程
    signal(SIGALRM,signal_catch);
    alarm(5);

    while (1)
    {
        printf("2222\n");
        sleep(2);
    }
    

    return 0;
}
void *pth_fun(void *pth_arg)
{
    while(1)
    {
        printf("1111\n");
        sleep(1);
    }

    return NULL;
}
void signal_catch(int signal_index)
{
    if(signal_index==SIGALRM)
    {
        //取消线程
        pthread_cancel(t_id);
    }
}
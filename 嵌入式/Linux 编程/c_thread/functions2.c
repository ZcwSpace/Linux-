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
    void *retval=NULL;

    //用线程函数来并发运行
    /*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/
    pthread_create(&pth.tid,NULL,pth_fun,NULL);
    signal(SIGALRM,signal_catch);
    alarm(2);
    //pthread_join(pth.tid,&retval);
    //printf("@@%s\n",(char *)retval);
    //pthread_detach(pth.tid);
    while (1)
    {
        printf("2222\n");
        sleep(2);
        
    }
    return 0;
}
void *pth_fun(void *pth_arg)
{
    //自己分离自己
    //pthread_detach(pth.tid);
    pthread_detach(pthread_self());
    for(int i=1; i<5; i++)
    {
        printf("1111\n");
        sleep(1);
    }

    return "运行结束！";
}
void signal_catch(int signal_index)
{
    if(signal_index==SIGALRM)
    {
        //取消线程
        pthread_cancel(pth.tid);
    }
}
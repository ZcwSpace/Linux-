#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<errno.h>
#include<string.h>
#include<signal.h>

//线程函数
void *pth_fun(void *pth_arg);
void print_error(char *str,int line,int err_no);
void signal_catch(int signal_index);

//定义一个变量来存放新属性
pthread_attr_t attr;

int main(void)
{
    pthread_t t_id=0;
    int pth_init_ret,pth_set_ret;

    signal(SIGINT,signal_catch);

    //调用int pthread_attr_init初始化一个attr结构体变量
    //int pthread_attr_init(pthread_attr_t *attr);
    pth_init_ret=pthread_attr_init(&attr);
    if(pth_init_ret!=0)
    {
        print_error("pthread_attr_init failed",__LINE__,errno);
    }
    //调用pthread_attr_setdetachstate预设分离属性
    pth_set_ret=pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
     if(pth_set_ret!=0)
    {
        print_error("pthread_attr_setdetachstate failed",__LINE__,errno);
    }
    
    pthread_create(&t_id,&attr,pth_fun,NULL);

    while (1)
    {
        printf("2222\n");
        sleep(3);
    }
}
void *pth_fun(void *pth_arg)
{
    for(int i=0;i<5;i++)
    {
        printf("1111\n");
        sleep(1);
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
    int pth_des_ret;
    pth_des_ret=pthread_attr_destroy(&attr);
    if(pth_des_ret!=0)
    {
        print_error("pthread_attr_destroy failed",__LINE__,errno);
    }

    exit(-1);
}
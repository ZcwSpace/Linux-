#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<errno.h>

//线程函数
void *pth_fun(void *pth_arg);
//出错处理函数
//print_err(char *str,int line,)
//定义条件变量
pthread_cond_t cond;
//直接初始化
//pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
//定义互斥锁,并直接初始化它
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

int main(void)
{
    pthread_t t_id=0;

    //初始化条件变量
    cond_init_ret=pthread_cond_init(&cond,NULL);
    pthread_create(&t_id,NULL,pth_fun,NULL);

    while (1)
    {
        pthread_mutex_lock(&mutex);
        va++;
        if(va==5)
        {
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&mutex);

        //每次循环递增需要间隔一段时间再进行，不然次线程检测不到
        sleep(1);
    }

    return 0;
}

void *pth_fun(void *pth_arg)
{
    
    while(1)
    {
        if(va==5)
        {
            printf("va=%d\n",va);
            va=0;
        }
    }

    return NULL;
}
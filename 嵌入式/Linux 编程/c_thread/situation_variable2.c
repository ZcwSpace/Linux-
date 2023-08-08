#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<errno.h>
#include<signal.h>

//线程函数
void *pth_fun(void *pth_arg);
//设置中断处理函数
void signal_catch(int signal_index);
//出错处理函数
//print_err(char *str,int line,)

//定义va
int va=0;
//定义条件变量
pthread_cond_t cond;
//直接初始化
//pthread_cond_t cond=PTHREAD_COND_INITIALIZER;

//定义互斥锁,并直接初始化它
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

//定义次线程编号
pthread_t t_id=0;


int main(void)
{
    //设置中断处理函数
    signal(SIGINT,signal_catch);

    //初始化条件变量
    pthread_cond_init(&cond,NULL);
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
        pthread_mutex_lock(&mutex);
        /*之所以将mutex传递给该函数，是害怕休眠后导致互斥锁没有解开，
        使得主线程无法加锁，无法按照计划正常运行。*/
        pthread_cond_wait(&cond,&mutex);
        {
            printf("va=%d\n",va);
            va=0;
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void signal_catch(int signal_index)
{
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    exit(0);
}
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
//定义全局变量va
int va=0;
//线程函数
void *pth_fun(void *pth_arg);

int main(void)
{
    pthread_t t_id=0;

    pthread_create(&t_id,NULL,pth_fun,NULL);

    while (1)
    {
        va++;
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
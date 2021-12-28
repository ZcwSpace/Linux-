#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>

//线程函数
void *pth_fun(void *pth_arg);

int main(void)
{
    //普通函数
    //pth_fun(NULL);

    //线程函数
    /*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/
    pthread_t t_id=0;
    pthread_create(&t_id,NULL,pth_fun,NULL);

    while (1)
    {
        printf("2222\n");
        sleep(3);
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
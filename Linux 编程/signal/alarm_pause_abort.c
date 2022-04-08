#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<sys/types.h>

void signal_catch(int signal_index);

int main(void)
{
    /*
    unsigned int ret;

    signal(SIGALRM,signal_catch);
    ret=alarm(5);
    sleep(2);
    ret=alarm(6);

    printf("ret=%d\n",ret);
    */
    /*
    signal(SIGINT,signal_catch);
    pause();
    printf("hello\n");
    */
    //abort();
    raise(SIGABRT);
    while(1);
    
    return 0;
}
void signal_catch(int signal_index)
{
    //printf("time up!\n");
}
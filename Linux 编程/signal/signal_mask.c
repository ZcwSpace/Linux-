#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include <sys/types.h>
#include <unistd.h>

void signal_catch(int signal_index);

int main(void)
{
    pid_t ret;

    signal(SIGINT,signal_catch);
    while(1);
    
    return 0;
}
/*
/处理信号的过程中，信号的屏蔽字被设置为1。再收到很多次该信号时，该信号被设置未处理信号集为1。等当前信号处理完成后，再将屏蔽字改为1，并去设置未处理信号为0，并处理该信号
*/
void signal_catch(int signal_index)
{
    sigset_t  set;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigprocmask(SIG_UNBLOCK,&set,NULL);

    printf("hello\n");
    sleep(3);
    printf("world\n");
}
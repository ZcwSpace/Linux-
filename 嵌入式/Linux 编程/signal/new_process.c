#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void signal_catch(int signal_index);

int main(void)
{
    signal(SIGINT,signal_catch);
    while (1)
    {
        /* code */
    };
    

    return 0;
}
void signal_catch(int signal_index)
{
    printf("new_pro pid=%d,signal=%d\n",getpid(),signal_index);
}
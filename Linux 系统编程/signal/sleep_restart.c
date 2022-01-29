#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<sys/types.h>
#include<errno.h>

void signal_catch(int signal_index);

int main(void)
{
    int ret=10;
    
    signal(SIGINT,signal_catch);

    //pause();
    
    //sleep(10);

    //重启pause
    /*
pause_restart:   
    ret=pause();
    if(ret==-1&&errno==EINTR)
    {
        goto pause_restart;
    }
    */

   //重启sleep
sleep_restart:
   //ret=sleep(10);
   ret=sleep(ret);
   if(ret!=0)
   {
       printf("remaining time=%d\n",ret);
       goto sleep_restart;
   }
    printf("hello\n");
    
    //while(1);

    return 0;
}
void signal_catch(int signal_index)
{
    //printf("time up!\n");
}
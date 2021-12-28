
#include <signal.h>

int main(void)
{
    //kill(getpid(),SIGUSR1);
    //kill(15673,SIGUSR1);
    raise(SIGKILL);

    while(1);
    
    return 0;
}

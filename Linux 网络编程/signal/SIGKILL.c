#include<stdio.h>
#include<stdlib.h>
#include <signal.h>

int main(void)
{

    for(int i=0;i<64;i++)
    {
        signal(i,SIG_IGN);
    }
    while(1);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include <signal.h>

int main(void)
{
   printf("SIG_DFL=%d",SIG_DFL);
   printf("SIG_IGN=%d",SIG_IGN);
   printf("SIG_ERR=%d",SIG_ERR);

    return 0;
}

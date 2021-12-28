#include<stdio.h>
#include<unistd.h>

int main(void)
{
  int ret=0;
  
  write(1,"Hello Deepin!\n",14);
  if(-1==ret)
    {
      perror("read fail:");
      return -1;
    }

  return 0;
}

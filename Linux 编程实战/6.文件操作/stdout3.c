#include<stdio.h>
#include<unistd.h>

int main(void)
{
  int ret=0;
  
  close(1);
  //ret=write(1,"Hello Deepin!\n",14);
  ret=printf("ret=%d",ret);
  if(-1==ret)
    {
      perror("read fail:");
      return -1;
    }
  
  return 0;
}

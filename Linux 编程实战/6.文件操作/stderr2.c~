#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(void)
{
  int ret=0;
  char *buf="Hello Deepin!";
  
  ret=write(2,buf,strlen(buf));
  write(2,"\n",1);
  if(-1==ret)
    {
      perror("read fail:");
      return -1;
    }

  return 0;
}

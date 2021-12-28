#include<stdio.h>
#include<unistd.h>

int main(void)
{
  int ret=0;
  char buf[10]={0};
  
  //ret=read(0,(void *)buf,10);
  close(0);
  ret=scanf("%s",buf);
  printf("EOF=%d\n",EOF);
  if(EOF==ret)
    {
      //perror("read fail:");
      perror("scanf fail:");
      return -1;
    }
  printf("buf=%s\n",buf);
  
  return 0;
}

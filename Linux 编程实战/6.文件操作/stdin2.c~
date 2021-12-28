#include<stdio.h>
#include<unistd.h>

int main(void)
{
  int ret=0;
  char buf[10]={0};
  int num=0;
  
  ret=read(0,(void *)buf,10);
  if(-1==ret)
    {
      perror("read fail:");
      return -1;
    }
  printf("buf=%s\n",buf);

  num=(buf[0]-'0')*100+(buf[1]-'0')*10+buf[2]-'0';
  printf("%d\n",num);
  
  return 0;
}

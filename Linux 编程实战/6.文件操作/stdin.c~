#include<stdio.h>
#include<unistd.h>

int main(void)
{
  int ret=0;
  char buf[10]={0};
  
  ret=read(0,(void *)buf,10);//100\n\0 12345678\n\0 123456789\n\0
  if(-1==ret)
    {
      perror("read fail:");
      return -1;
    }
  //printf("buf=%s",buf);
  for(int i=0;buf[i]!='\0';i++)
    {
      printf("%d",buf[i]);
    }
  return 0;
}

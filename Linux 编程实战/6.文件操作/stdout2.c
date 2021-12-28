#include<stdio.h>
#include<unistd.h>

int main(void)
{
  int ret=0;
  char *va="65";
  
  ret=write(1,va,2);
  write(1,"\n",1);
  if(-1==ret)
    {
      perror("read fail:");
      return -1;
    }

  return 0;
}

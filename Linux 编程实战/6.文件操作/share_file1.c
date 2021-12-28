#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#define FILENAME "./file.txt"

void print_error(char *str);

int main(void)
{
  int fd1=0,fd2=0;

  fd1=open(FILENAME,O_RDWR|O_TRUNC|O_APPEND);
  if(fd1==-1)
    {
      print_error("1 open fail");
    }
  printf("fd1=%d",fd1);
  while(1)
    {
      write(fd1,"hello\n",6);
      sleep(1);
    }//相互覆盖
  
  return 0;
}
void print_error(char *str)
{
   perror(str);
   exit(0);
}

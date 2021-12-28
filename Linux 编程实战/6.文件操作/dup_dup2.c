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

  fd1=open(FILENAME,O_RDWR|O_TRUNC);
  if(fd1==-1)
  {
      print_error("open fail");
  }
  //fd2=dup(fd1);
  fd2=dup2(fd1,4);
  //fd2=4;
  //dup2(fd1,fd2);

  printf("fd1=%d,fd2=%d\n",fd1,fd2);

  while (1)
  {
    write(fd1,"hello\n",6);
    sleep(1);
    write(fd2,"world\n",6);
  }

  return 0;
}
void print_error(char *str)
{
   perror(str);
   exit(0);
}

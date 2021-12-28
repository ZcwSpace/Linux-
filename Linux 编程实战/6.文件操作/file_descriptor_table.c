#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(void)
{
  int fd=0;
  inrt ret=0;

  fd=open("./file.txt",O_RDONLY);
  if(-1=fd)
    {
      perror("open fail");
      exit(0);
    }
  ret=write(fd,"Hello World!",12);
  if(ret==-1)
    {
      perror("write fail");
      exit(0);
    }

  return 0;
}

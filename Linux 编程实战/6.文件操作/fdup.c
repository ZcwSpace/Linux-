#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<error.h>
#include<string.h>

int main(void)
{
  int fd=0;

  fd=open("./file.txt",O_RDWR);
  if(-1==fd)
  {
      printf("open fail:%d\n",error);
      return 0;
  }
  //模拟dup1
  close(1);
  /*fcntl(fd,F_DUPFD,0);*/
  //模拟dup2
  fcntl(fd,F_DUPFD,1);

  printf("relocate!");
  return 0;
}

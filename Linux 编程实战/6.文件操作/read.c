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

  fd=open("./file.txt",O_RDWR|O_CREAT,0664);
  if(-1==fd)
    {
      printf("open fail:%d\n",error);
      return 0;
    }
  else
    {
      printf("open ok\n");
      printf("fd=%d\n",fd);
    }

  char buf2[30]={0};
  //read(fd,buf2,11);
  read(fd,buf2+3,11);
  
  //printf("buf2=%s\n",buf2);
  printf("buf2=%s\n",buf2+3);
  
  for(int i=0;i<3;i++)
    {
      printf("%c",buf2[i]);
    }
  printf("\n");
 
  return 0;
}

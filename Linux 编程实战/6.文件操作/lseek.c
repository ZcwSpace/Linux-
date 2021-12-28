#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(void)
{
  int ret,fd;

  fd=open("./file.txt",O_RDWR);
  if(fd==-1)
    {
      perror("open fail:");
      exit(0);
    }
  //ret=lseek(fd,0,SEEK_END);
  //ret=lseek(fd,-10,SEEK_END);
  //ret=lseek(fd,-10,SEEK_SET);
  //ret=lseek(fd,10,SEEK_CUR);
  ret=lseek(fd,10,SEEK_END);
  if(ret==-1)
    {
      perror("can't move");
      exit(0);
    }
  //printf("size of file：%d\n",ret);
  char buf[30]={0};
  
  read(fd,buf,10);
  printf("buf=%s\n",buf);
  
  return 0;
}

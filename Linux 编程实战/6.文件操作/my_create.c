#include<stdio.h>
#include<stdlib.h>
//strerror的头文件
#include<string.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main()
{
  int fd;

  //if((fd=open("example_62.c",O_CREAT|O_EXCL,S_IRUSR|S_IWUSR/*文件所有者可读可写*/))==-1){
      if((fd=creat("example_62.c",S_IRWXU))==-1){
      //perror("open");
      printf("open:%s with error:%d\n",strerror(errno),errno);
      exit(1);
    }
  else
    {
      printf("create file success\n");
    }
  close(fd);
  
  return 0;
}

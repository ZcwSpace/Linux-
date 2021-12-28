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
  char c;

  //fd1=open(FILENAME,O_RDWR|O_TRUNC);
  fd1=open(FILENAME,O_RDWR);
  if(fd1==-1)
  {
      print_error("open fail");
  }
  //重定位：改变文件描述符指向的文件
  //close(1);
  //dup(fd1);
  dup2(3,0);
  //printf("relocate success!");
  scanf("%c",&c);
  printf("c=%c",c);
  return 0;
}
void print_error(char *str)
{
   perror(str);
   exit(0);
} 

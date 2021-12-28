#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<error.h>
#include<string.h>

int open_func1(void);
int open_func2(void);

int main(void)
{
  int fd1=0,fd2=0;
  int flag=0;

  fd1=open_func1();
  fd2=open_func2();
  /*直接指定F_SETFL时，会直接使用新的标志，去修改掉老的标志
  返回新设置的标志*/
  /*
  flag=O_RDWR|O_TRUNC|O_APPEND;
  fcntl(fd1,F_SETFL,flag);
  fcntl(fd2,F_SETFL,flag);
  */
  /*保留原有标志，在原有标志的基础上，叠加新标志*/
  
  flag=fcntl(fd2,F_GETFL,0);
  flag|=O_TRUNC|O_APPEND;
  fcntl(fd1,F_SETFL,flag);
  fcntl(fd2,F_SETFL,flag);
  
  while (1)
  {
    write(fd1,"hello\n",6);
    sleep(1);
    write(fd2,"world\n",6);
  }
  

  return 0;
}
int open_func1(void)
{
  int fd=open("./file.txt",O_RDWR);
  if(-1==fd)
  {
      printf("open fail:%d\n",error);
      return 0;
  }
  return fd;
}
int open_func2(void)
{
  int fd=open("./file.txt",O_RDWR);
  if(-1==fd)
  {
      printf("open fail:%d\n",error);
      return 0;
  }
  return fd;
}
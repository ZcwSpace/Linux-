#include<stdio.h>
#include<string.h>
/*lseek函数头文件：#include<sys/types.h> #include<unistd.h>*/
//open函数的头文件
#include<sys/types.h>//基本系统数据类型
#include<sys/stat.h>//是unix/linux系统定义文件属性所在的伪标准头文件
#include<fcntl.h>//fcntl.h定义了很多宏和open,fcntl函数原型
//wirte read函数的头文件
#include<unistd.h>//包含了许多UNIX系统服务的函数原型，例如read函数、write函数和getpid函数。
int main(void)
{
  int fd;
  int ret;
  fd=open("file.txt",O_RDWR);//“./”不写也行
  //fd=open("file.txt",O_RDONLY|);
  //fd=open("file.txt",O_WRONLY)
  //fd=open("file.txt",O_RDWR|O_APPEND);
  //
  if(fd==-1)
    {
      printf("open fail\n ");
      return 0;
    }
  else
    {
      printf("open ok\n");
    }
  
  char buf[]="Hello World!";
  ret=write(fd,(void *)buf,strlen(buf));
  if(ret==-1)
    {
      printf("write fail\n");
      return 0;
    }

  lseek(fd,SEEK_SET,0);
  
  char buf2[30]={0};
  ret=read(fd,buf2,sizeof(buf2));
  if(ret==-1)
    {
      printf("read fail\n");
      return 0;
    }
  
  printf("buf2=%s\n",buf2);

  close(fd);
  return 0;
}

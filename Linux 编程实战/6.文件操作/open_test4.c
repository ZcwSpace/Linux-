#include<stdio.h>
#include<string.h>
/*lseek函数头文件：#include<sys/types.h> #include<unistd.h>*/
//open函数的头文件
#include<sys/types.h>//基本系统数据类型
#include<sys/stat.h>//是unix/linux系统定义文件属性所在的伪标准头文件
#include<fcntl.h>//fcntl.h定义了很多宏和open,fcntl函数原型
//wirte read函数的头文件
#include<unistd.h>//包含了许多UNIX系统服务的函数原型，例如read函数、write函数和getpid函数。
//error函数的头文件
#include<error.h>//包含了一些错误号宏名
int main(void)
{
  int fd;

  //fd=open("./file.txt",O_RDWR);//“./”不写也行
  //fd=open("./file.txt",O_RDWR|O_CREAT|O_EXCL,0665);
  fd=open("./file.txt",O_RDWR);
  if(fd==-1)
    {
      //printf("open fail\n ");
      printf("open fail:%d\n",error);
      perror("openfile");
      return 0;
    }
  else
    {
      printf("open ok\n");
    }
  
  char buf[]="Hello World";
  write(fd,(void *)buf,strlen(buf));

  lseek(fd,SEEK_SET,0);
  
  char buf2[30]={0};
  read(fd,buf2,sizeof(buf2));
  
  printf("buf2=%s\n",buf2);

  close(fd);
  return 0;
}

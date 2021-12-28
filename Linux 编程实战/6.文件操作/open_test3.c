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
  int ret=0;
  
  fd=open("./file5.txt",O_RDWR|O_CREAT,0777);//“./”不写也行
  //fd=open("./file.txt",O_RDWR|O_CREAT|O_EXCL,0664);
  if(fd==-1)
    {
      printf("open fail\n ");
      return 0;
    }
  else
    {
      printf("open ok\n");
      printf("fd=%d\n",fd);
    }
  
  char buf[]="Hello World";
  write(fd,(void *)buf,strlen(buf));

  lseek(fd,0,SEEK_SET);
  
  char buf2[30]={0};
  read(fd,buf2,sizeof(buf2));
  
  ret=printf("buf2=%s\n",buf2);
  printf("ret=%d\n",ret);
  close(fd);
  
  fd=open("./file1.txt",O_RDWR|O_CREAT,0664);
  printf("fd=%d\n",fd);
  
  close(fd);
  
  return 0;
}

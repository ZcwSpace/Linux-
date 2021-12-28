#include<stdio.h>
#include<string.h>
/*lseek函数头文件：#include<sys/types.h> #include<unistd.h>*/
//open函数的头文件
#include<sys/types.h>//基本系统数据类型
#include<sys/stat.h>//是unix/linux系统定义文件属性所在的伪标准头文件
#include<fcntl.h>//fcntl.h定义了很多宏和open,fcntl函数原型
//wirte read函数的头文件
#include<unistd.h>//包含了许多UNIX系统服务的函数原型，例如read函数、write函数和getpid函数。
int main(int argc,char** argv)
{
  int fd=0;
  
  if(argc==3)
  {
    fd=link(argv[1],argv[2]);
  }
  else if(argc==2)
  {
    fd=unlink(argv[1]);
  }
  else
  {
    printf("输入错误!");
    return 0;
  }
  if(fd==-1)
  {
    perror("error");
  }
}

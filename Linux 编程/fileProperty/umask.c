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
  int fd=0;
  mode_t ret=0;
  
  ret=umask(0222);
  printf("oldmask=%o\n",ret);

  fd=open("./file5.txt",O_RDWR|O_CREAT,0777);//“./”不写也行
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
    ret=umask(0222);
    printf("oldmask=%o\n",ret);
  close(fd);
  
  return 0;
}

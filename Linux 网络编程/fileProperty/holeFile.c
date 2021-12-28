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

  //truncate("file5.txt",10);
  
  fd=open("hole_file.txt",O_RDWR|O_CREAT,0664);//“./”不写也行
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
  //ftruncate(fd,800);
  lseek(fd,800,SEEK_SET);
  write(fd,"hello",5);
  close(fd);
  //du:查看文件在块设备上实际占用的物理空间
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
//获取文件的大小 
int get_file_size(int f)
{
  struct stat st;
  fstat(f, &st);
  return st.st_size;
}
int main(int argc,char**argv)
{
 int fd = open(argv[1],O_RDWR);
 int size ;
 if(fd < 0)
 {
 printf("open fair!\n");
 return -1 ;
 }
 size = get_file_size(fd) ;
 printf("size:%d字节--->%.2fK\n",size,(float)size/1024);
 return 0 ; 
}
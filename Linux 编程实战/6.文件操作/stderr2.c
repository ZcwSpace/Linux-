#include<stdio.h>
#include<unistd.h>
#include<string.h>
/*
三个宏：STDERR_FILENO STDIN_FILENO STDOUT_FILENO
*/
int main(void)
{
  int ret=0;
  char *buf="Hello Deepin!";

  close(STDERR_FILENO);
  perror("fail");
  
  return 0;
}

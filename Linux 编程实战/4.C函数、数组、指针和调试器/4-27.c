#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  char a;
  char *str=&a;

  str=(char *)malloc(strlen("hello")+1);
  strcpy(str,"hello");
  printf("%s\n",str);
  free(str);
  return 0;
}

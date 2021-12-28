//连接两个字符串
#include<stdio.h>

char *connectString(char *dest,char *src);

int main()
{
  char d[20]="Hello ";
  char *s="World";

  printf("连接后的字符串为：%s\n",connectString(d,s));

  return 0;
}
char *connectString(char *dest,char *src)
{
  char *temp;
  temp=dest;
  while(*temp!='\0')
    {
      temp++;
    }
  while(*src!='\0')
    {
      *temp=*src;
      temp++;
      src++;
    }
  temp='\0';

  return dest;
}

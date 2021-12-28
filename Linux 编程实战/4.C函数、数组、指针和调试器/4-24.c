#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void fun(char str[100]);

int main()
{
  char str[]="Hello";
  char *p1=str;
  int n=10;
  char *p2=(char *)malloc(100);

  printf("%d\n",sizeof(str));//6
  printf("%d\n",strlen(str));//5

  printf("%d\n",sizeof(p1));//4 8
  printf("%d\n",strlen(p1));//5

  printf("%d\n",sizeof(n));//4
  printf("%d\n",sizeof(p2));//4 8
  fun(p2);//8

  printf("\n");

  return 0;
}
void fun(char str[100])
{
  printf("%d\n",sizeof(str));
}

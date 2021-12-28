#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  char str[]="ABCD1234efgh";
  int length=strlen(str);//length=12
  char *p1=str;//*p1=A
  char *p2=str+length-1;//*p2=h

  while(p1<p2)
    {
      char c=*p1;
      *p1=*p2;
      *p2=c;


      ++p1;
      --p2;
    }
  printf("string now is %s\n",str);

  return 0;
}

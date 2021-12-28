//字符串倒序
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  char *src="hello,world";
  char *dest=NULL;

  int len=strlen(src);//len=11
  dest=(char *)malloc(len+1);//wrong 1:dest=(char *)malloc(len);
  char *d=dest;
  char *s=&src[len-1];//wrong 2:char *s=&src[len];
  while(len--!=0)
    {
      *d++=*s--;
    }
  *d='\0';//wrong 3:
  printf("%s\n",dest);
  free(dest);//wrong 4:
  return 0;
}

#include<stdio.h>
/*
int main()
{
  int i;
  float f=1;

  for(i=1;i<=10;i++)
    {
      f=f*i;
    }

  printf("10!=%10.0f\n",f);//362800
}
*/
#include<stdio.h>

float fac(int n);

int main()
{
  int n=10;
  float f;
  
  f=fac(n);

  printf("10!=%10.0f\n",f);
}
float fac(int n)
{
  float f;

  if(n<0)
    {
      printf("n<0,数据错误!");
      return -1;
    }
  else if(n<=1)
    {
      f=1;
    }
  else
    {
      f=n*fac(n-1);
    }
  return f;
}

#include<stdio.h>
#define get_max(a,b,c) (a>b? (a>c? a:c):(b>c? b:c))

int getMax(int a,int b,int c);

int main()
{
  int a=5,b=6,c=10;

  printf("函数返回最大数为：%d\n",getMax(a,b,c));
  printf("宏定义返回最大数为：%d\n",get_max(a,b,c));
  return 0;
}
int getMax(int a,int b,int c)
{
  int max;
  if(a<b)
    {
      max=b;
      if(b<c)
	{
	  max=c;
	}
    }
  else//a>b
    {
      if(a<c)
	{
	  max=c;
	}
    }
  return max; 
}

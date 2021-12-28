#include<stdio.h>
int main()
{
  int i,sum=0,flag=0;
  char killer;
  for(i=1;i<=4;i++)
    {
      killer=64+i;
      sum=(killer!='A')+(killer=='C')+(killer=='D')+(killer!='D');

      if(sum==3)
	{
	  flag=1;
	  printf("凶手是：%c。\n",killer);
	}
    }
  if(flag==0)
    {
      printf("没找到\n");
    }
  return 0;
}
      

#include<stdio.h>
int main()
{
  int i;
  for(i=11;i;i++)
    {
      if(i%2==1&&i%3==2&&i%5==4&&i%6==5&&i%7==0)
	{
	  printf("阶梯为：%d\n",i);
	  break;
	}      
    }
  return 0;
}

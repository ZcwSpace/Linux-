#include<stdio.h>
#include<string.h>

void operate(int* n,char sign,int* m,int *r);
void compare(int *n,int m);

int main()
{
  int n[100]={8,8,6,9,9,1,7,0,8,0,0,2,8,8};
  int m[100]={8,7,6,5,4,3,2,1,9,8,7,6,5,4,3};
  int r[100]={0};
  int i;
  
  operate(m,'*',n,r);
  printf("运算后的数字为：");
  for(i=99;i>-1;i--)
    {
      if(r[i]!=0)
	{
	  break;
	}
    }
  for(;i>-1;i--)
    {
      printf("%d",r[i]);
    }
  printf("\n");
  
  return 0;
}
void operate(int *n,char sign,int *m,int *r)
{
  int i,j,k=0;
  switch(sign)
    {
    case '+':
      for(i=0;i<100;i++)
	{
	  if(n[i]+m[i]>9)//16
	    {
	      ++r[i+1];
	      r[i]=r[i]+n[i]+m[i]-10;
	    }
	  else
	    {
	      r[i]=r[i]+n[i]+m[i];
	    }
	}
      break;
    case '-':
      for(i=0;i<100;i++)
	{
	  if(n[i]-m[i]<0)
	    {
	      n[i+1]--;
	      r[i]=n[i]+10-m[i];
	    }
	  else
	    {
	      r[i]=n[i]-m[i];
	    }
	}
      break;
    case '*':
      for(i=0;i<100;i++)//m
	{
	  k=i;
	  for(j=0;j<100;j++,k++)//n
	    {
	      if(n[j]*m[i]>9)
		{
		  compare(&r[k+1],n[j]*m[i]/10);
		  compare(&r[k],n[j]*m[i]%10);
		}
	      else
		{
		  compare(&r[k],n[j]*m[i]);
		}
	    }
	}
      break;
    default:
      printf("对于该符号的运算尚未开发!\n");
    }
}
void compare(int *n,int m)
{
  if((*n)+m>9)
  {
    ++*(n+1);
    *n=*n+m-10;
  }
  else
  {
    *n=*n+m;
  }
}

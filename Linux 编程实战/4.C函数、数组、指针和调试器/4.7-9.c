#include<stdio.h>

void statistics(int (*a)[][5],int (*b)[][10]);

int main()
{
  int a[][5]={1,1,1,1,1,2,2,2,2,2};
  int b[][10]={{0},{0}};
  int i,j;

  statistics(&a,&b);
  for(i=0;i<9;i++)
    {
      if(b[0][i]==0)
	{
	  break;
	}
    }
  printf("共有%d个互不相同的数\n",i);
  printf("每个数出现的频率如下:\n");
  for(j=0;j<i;j++)
    {
      printf("%d:",b[0][j]);
      printf("%d次\n",b[1][j]);
    }
    
  return 0;
}
void statistics(int (*a)[][5],int (*b)[][10])
{
  int i,j,m;
  int flag;
  for(i=0;i<2;i++)
    {
      for(j=0;j<5;j++)
	{
	  flag=0;
	  for(m=0;m<9;m++)
	    {
	      if((*a)[i][j]==(*b)[0][m])
		{
		  flag=1;
		  break;
		}
	    }
	  if(flag==0)
	    {
	      for(m=0;m<9;m++)
		{
		  if((*b)[0][m]==0)
		    {
		      (*b)[0][m]=(*a)[i][j];
		      (*b)[1][m]=1;
		      break;
		    }
		}
	    }
	  else
	    {
	      (*b)[1][m]++;
	    }
	}
    }
}

#include<stdio.h>

int getSecondMax(int array[][3],int w,int l,int max,int sMax);

int main()
{
  int array[][3]={1,2,3,58,98,45};
  int max,sMax;
  if(array[0][0]>array[0][1])
     {
       max=array[0][0];
       sMax=array[0][1];
     }
   else
     {
       max=array[0][1];
       sMax=array[0][0];
     }
  printf("该数组第二大的元素为：%d\n",getSecondMax(array,0,2,max,sMax));
  
  return 0;
}
int getSecondMax(int array[][3],int w,int l,int max,int sMax)
{
  if(array[w][l]>max)
    {
      sMax=max;
      max=array[w][l];
    }
  else if(array[w][l]>sMax)
    {
      sMax=array[w][l];
    }
  if(l==2)
    {
      if(w==1)
	{
	  return sMax;
	}
      w++;
      l=0;
     }
  else
    {
      l++;
    }
  return getSecondMax(array,w,l,max,sMax);
}

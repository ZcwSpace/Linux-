#include<stdio.h>

int getMax(int *array,int length,int max);

int main()
{
  int array[]={1,45,98,68,35,20};

  printf("该数组中最大值是：%d\n",getMax(array,sizeof(array)/4,array[0]));

  return 0;
}
int getMax(int *array,int length,int max)
{
  if(length==0)
    {
      return max;
    }
  if(*array>max)
    {
      max=*array;
    }
  return getMax(array+1,length-1,max);
}

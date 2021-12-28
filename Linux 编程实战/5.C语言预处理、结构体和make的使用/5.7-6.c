#include<stdio.h>

int func(int x);

int main()
{
  int a=127;
  printf("数字以二进制表示时1的个数为：%d\n",func(a));
  
  return 0;
}
int func(int x)
{
  int count=0;

  while(x)
    {
      count++;
      x=x&(x-1);
    }
  
  return count;
}

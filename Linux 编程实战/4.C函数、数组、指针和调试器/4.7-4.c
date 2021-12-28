#include<stdio.h>

int f(int n);

int main()
{
  int n;
  printf("请输入一个数字：");
  scanf("%d",&n);
  printf("结果为：%d",f(n));
  
  return 0;
}
int f(int n)
{
  switch(n)
    {
    case 1:
    case 2:
      return 1;
    default:
      return f(n-1)+f(n-2);
    }
}

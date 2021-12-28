#include<stdio.h>
int main()
{
  int a,b;
  printf("请输入两个整数:");
  scanf("%d,%d",&a,&b);

  printf("积：%d\n",a*b);
  printf("余数：%d\n",a%b);
  printf("平均数：%d\n",(a+b)/2);
}

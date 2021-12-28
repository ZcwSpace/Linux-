#include<stdio.h>
int main()
{
  int a=1,b=2,temp;
  temp=a;
  a=b;
  b=temp;

  printf("a is %d",a);
  printf("b is %d",b);

  a=a+b;
  b=a-b;
  a=a-b;
  printf("a is %d",a);
  printf("b is %d",b);
}

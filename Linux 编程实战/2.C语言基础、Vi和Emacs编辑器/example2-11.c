#include<stdio.h>
int main()
{
  int a,b,c,d;

  a=10;
  b=a++;//b= 10, a=11
  c=++a;//c=12,a=12
  d=20+a++;//d=32,a=13

  printf("b,c,d:%d,%d,%d",b,c,d);
}

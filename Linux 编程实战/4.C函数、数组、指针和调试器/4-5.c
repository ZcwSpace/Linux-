#include<stdio.h>

int max(int a,int b);

int main()
{
  extern int i,j;
  printf("%d\n",max(i,j));
}
int max(int a,int b)
{
  return a>b? a:b;
}
int i=-5,j=10;

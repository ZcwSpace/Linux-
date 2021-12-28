#include<stdio.h>

int max(int a,int b);

int main()
{
  int i,j=10,k=15;

  i=max(j,k);
  
  printf("i=%d\n",i);
}
int max(int a,int b)
{
  int c;
  
  c=a>b? a:b;
  
  return c;
}

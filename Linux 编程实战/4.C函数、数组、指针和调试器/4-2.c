#include<stdio.h>
/*
int myabs(int x);

int main()
{
  int x;
  
  scanf("%d",&x);
  x=myabs(x);
  
  printf("%d\n",x);
}
int myabs(int x)
{
  return (x>0? x:-x);
}
*/
int myabs(int x);

int main()
{
  float x;
  
  scanf("%f",&x);
  x=myabs(x);
  
  printf("%f\n",x);
}
int myabs(int x)
{
  return (x>0? x:-x);
}

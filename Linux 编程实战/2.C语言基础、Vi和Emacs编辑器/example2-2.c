#include<stdio.h>
int main()
{
  short int s;
  int i;
  long int l;
  int a,b,c;

  a=sizeof(s);
  b=sizeof(i);
  c=sizeof(l);
  
  printf("a is %d\n",a);
  printf("b is %d\n",b);
  printf("c is %d\n",c);

  return 0;
}
  
  

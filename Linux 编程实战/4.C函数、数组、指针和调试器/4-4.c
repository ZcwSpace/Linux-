#include<stdio.h>

void function();

int main()
{
  function();
  function();
  function();
}
void function()
{
  static int a=0;
  int b=0;

  a++;
  b++;

  printf("a=%d,b=%d\n",a,b);
}

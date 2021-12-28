#include<stdio.h>

void change(int i,int *p);

int main()
{
  int a=5,b=10;

  change(a,&b);

  printf("a=%d b=%d\n",a,b);//5 11

  return 0;
}
void change(int i,int *p)
{
  i++;
  if(p!=NULL)
    {
      (*p)++;
    }
}

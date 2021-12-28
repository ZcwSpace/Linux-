#include<stdio.h>

int inc(int a);
int multi(int *a,int *b,int *c);
int (*p)(int);
void show(int(*fun)(int *,int *,int *),int arg1,int *arg2);

int main()
{
  int a;
  show(multi,10,&a);

  return 0; 
}
int inc(int a)
{
  return (++a);
}
int multi(int *a,int *b,int *c)
{
  return (*c=*a**b);
}
void show(int(*fun)(int *,int *,int *),int arg1,int *arg2)
{
  p=&inc;
  int temp=p(arg1);//temp=11
  fun(&temp,&arg1,arg2);//*arg2=11*10=110
  printf("%d\n",*arg2);
}

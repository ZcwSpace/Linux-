#include<stdio.h>
int main()
{
  int a=100,b=200;
  int *p1=&a,*p2=&b;

  printf("%d,%d\n",a,b);//100 200
  printf("%d,%d\n",*p1,*p2);//100 200
  printf("%x,%x\n",&a,&b);//a的地址 b的地址
  printf("%x,%x\n",p1,p2);//a的地址 b的地址

  *p1=*p1*3;
  printf("%d\n",a);//300
  printf("%d,\n\n",*p1);//300

  p1=&b;
  printf("%x\n",p1);//b的地址
  printf("%x\n",p2);//b的地址

  return 0;
}

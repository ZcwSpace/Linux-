#include<stdio.h>
int main()
{
  int i=3,j,k;

  j=i++;//j=3
  k=++i;//k=5

  printf("i=%d.j=%d,k=%d\n",i,j,k);// 5 3 5
  printf("%d\n",-i--);// -5
  printf("%d,%d,%d",i,i++,i++);//6  5  4
}

  

#include<stdio.h>

int main(void)
{
  char *a="123.45";
  float aim;

  aim=(a[0]-'0')*100+(a[1]-'0')*10+a[2]-'0'+(a[4]-'0')*0.1+(a[5]-'0')*0.01;

  printf("aim=%.2f\n",aim);
  
  return 0;
}
  

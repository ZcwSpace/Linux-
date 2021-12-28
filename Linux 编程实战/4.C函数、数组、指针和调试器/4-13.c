#include<stdio.h>

char *name[7]={"Mondy","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

char *message="wrong input";

char *week(int day);

int main()
{
  int day;
  char *p;

  printf("输入一个周一个数字：");
  scanf("%d",&day);

  p=week(day);
  
  printf("%s\n",p);

  return 0;
}
char *week(int day)
{
  if(day<1||day>7)
    {
      return message;
    }
  else
    {
      return name[day-1];
    }
}

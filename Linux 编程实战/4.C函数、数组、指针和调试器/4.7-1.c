#include<stdio.h>

int stringLength(char *string);

int main()
{
  char *string;

  printf("字符串的长度为%d\n",stringLength(string));
    
  return 0;
}
int stringLength(char *string)
{
  if(string==NULL)
    {
      printf("输入的指针为空指针！\n");
      return 0;
    }
  int number;
  for(number=0;*string!='\0';string++)
    {
      number++;
    }
  return number;
}

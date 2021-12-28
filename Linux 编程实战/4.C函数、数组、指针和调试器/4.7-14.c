#include<stdio.h>
#include<string.h>
void compare(char *str1,char *str2);

int main()
{
  char *str1="Hello World!";
  char *str2="Linux Pregramming!";

  compare(str1,str2);
  
  return 0;
}
void compare(char *str1,char *str2)
{
  if(strlen(str1)>strlen(str2))
    {
      printf("1\n"); 
    }
  else if(strlen(str1)==strlen(str2))
    {
      printf("0\n");
    }
  else
    {
      printf("-1\n");
    }
}

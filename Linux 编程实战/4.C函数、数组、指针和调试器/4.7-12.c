#include<stdio.h>
#include<string.h>

void changeString(char *string1,char *string2);

int main()
{
  char str1[]="Linux.C";
  char str2[]="Hello World!";

  changeString(str1,str2);

  printf("str1:%s\n",str1);
  printf("str2:%s\n",str2);
  
  return 0;
}
void changeString(char *string1,char *string2)
{
  char tempStr;
  int i,length;

  length=strlen(string1)>=strlen(string2)? strlen(string1):strlen(string2);
  for(i=0;i<length;i++)
    {
      tempStr=string1[i];
      string1[i]=string2[i];
      string2[i]=tempStr;
    }
  string2[i]='\0';
  string1[i]='\0';
}

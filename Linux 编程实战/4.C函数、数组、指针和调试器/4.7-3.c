#include<stdio.h>

void stringDelete(char *s,int i,int n);

int main()
{
  char s[]="123456789";
  stringDelete(s,2,3);
  printf("删除后的字符串为%s\n",s);

  return 0;
}
void stringDelete(char *s,int i,int n)
{
  if(s==NULL)
    {
      printf("输入指针为空！");
      return ;
    }
  
  char *temp1,*temp2;
  
  temp1=s+i-1;
  temp2=temp1+n;
  while(*temp2!='\0')
    {
      *temp1=*temp2;
      temp1++;
      temp2++;
    }
  *temp1='\0';
}

#include<stdio.h>
#include<string.h>

void commonString(char *str1,char *str2);

int main()
{
  char *str1="10203455";
  char *str2="1111203455";
  
  commonString(str1,str2);
  
  return 0;
}
void commonString(char *str1,char *str2)
{
  int i,j,address,max;
  int text[strlen(str1)][strlen(str2)];
  
   for(i=0;i<strlen(str1);i++)
    {
      for(j=0;j<strlen(str2);j++)
	{
	  text[i][j]=0;
	}
    }
   for(i=0;i<strlen(str1);i++)
    {
      for(j=0;j<strlen(str2);j++)
	{
	  if(str1[i]==str2[j])
	    {
	      if(i==0||j==0)
		{
		  text[i][j]=1; 
		}
	      else
		{
		  text[i][j]=text[i-1][j-1]+1;
		}
	    }
	}
    }
   
  max=0;
  for(i=0;i<strlen(str1);i++)
    {
      for(j=0;j<strlen(str2);j++)
	{
	  if(text[i][j]>max)
	    {
	      address=i;
	      max=text[i][j];
	    }
	}
    }
  for(i=address-max+1,j=0;i<=address;i++,j++)
    {
      printf("%c",str1[i]);
    }
  printf("\n");
}


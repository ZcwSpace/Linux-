#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findnumstring(char *outputstr,char * inputstr);

void main()
{
  char string[]="abcd12345eee125ss123456789";
  char *p=(char *)malloc(strlen(string)+1);

  int count=findnumstring(p,string);
  printf("%s\nnumber string length=%d\n",p,count);
}
int findnumstring(char *outputstr,char * inputstr)
{
  char *in=inputstr,*out=outputstr,*temp,*final;
  int count =0,maxlen=0;
  while(*in!='\0')
    {
      if(*in>47&&*in<58)
	{
	  for(temp=in;*in>47&&*in<58;in++)
	    {
	      count++;
	    }
	}
      else
	{
	  in++;
	}
      if(maxlen<count)
	{
	  maxlen=count;
	  final=temp;
	}
      count=0;
    }
  for(int i=0;i<maxlen;i++)
    {
      *out=*final;
      out++;
      final++;
    }
  *out='\0';

  return maxlen;
}

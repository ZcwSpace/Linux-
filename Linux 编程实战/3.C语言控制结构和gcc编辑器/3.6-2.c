#include<stdio.h>
int main()
{
  int z,x,c,v,b,sum;
  char one,two,three,four,five;
  for(z=1;z<=5;z++)
    {
      one=64+z;
      for(x=1;x<=5;x++)
	{
	  two=64+x;
	  if(two!=one)
	    {
	      for(c=1;c<=5;c++)
		{
		  three=64+c;
		  if(three!=two&&three!=one)
		    {
		      for(v=1;v<=5;v++)
			{
			  four=64+v;
			  if(four!=three&&four!=two&&four!=one)
			    {
			      for(b=1;b<=5;b++)
				{
				  five=64+b;
				  if(five!=four&&five!=three&&five!=two&&five!=one)
				    {
				      sum=(one=='B'||three=='A')&&(two=='B'||four=='E')&&(one=='C'||two=='D')&&(five=='C'||three=='D')&&(four=='E'||one=='A');
				      if(sum==1)
					{
					  printf("one：%c two:%c three:%c four:%c five:%c\n",one,two,three,four,five);
					  return 0;
					}
			
				    }
				}
			    }
			}
		    }
		     
		}
	    }
	    
	}
    }
  printf("程序错误了！\n");
  return 0;
}
 

#include "stdio.h"

int max(int x, int y, int z);

int main()
{ 
    int a,b,c,d;
    
    scanf("%d,%d,%d",&a,&b,&c);
    d=max(a,b,c);
    printf("max=%d\n",d);
    
    return 0;

}

int max(int x, int y, int z)
{ 
    int s;

    if(x>=y && x>=z)//如果为真，则x为最大值；如果不为真，则最大值为y或=z
	    s=x;
    if(y>=x && y>=z)//如果为真，则y为最大值；如果不为真，则最大值为z
	    s=y;
    else
	    s=z;
  
    return(s);
}
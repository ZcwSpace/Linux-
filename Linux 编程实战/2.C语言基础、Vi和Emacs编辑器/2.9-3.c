
#include<stdio.h>
int main()
{
	int a=12,n=5;
	a+=a;
	printf("%d",a);
	a=12,n=5;
	a%=7;
	printf("%d",a);
	a=12,n=5;
	a*=2+5;
	printf("%d",a);
	a=12,n=5;
	a/=a+a;
	printf("%d",a);
	a=12,n=5;
	a%=(n%=2);
	printf("%d",a);
	a=12,n=5;
	a-=a+=a*=a;
	printf("%d",a);
}

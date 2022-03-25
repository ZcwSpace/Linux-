#include <stdio.h>

#define LENGTH 10

int main(void)
{
	int a[LENGTH];

	for(int i=0;i<LENGTH;i++)
	{
		printf("请输入第%d个数：",i+1);
		scanf("%d",&a[i]);
	}

	printf("before sorted:");
	for(int i=0;i<LENGTH;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");

	int temp;

	for(int i=0;i<LENGTH-1;i++)
	{
		for(int j=i+1;j<LENGTH;j++)
		{
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}

	printf("after sorted:");
	for(int i=0;i<LENGTH;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;

}

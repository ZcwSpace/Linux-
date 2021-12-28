#include<stdio.h>

int main(void)
{
	float a,b,sides_triangle[2];
	
	printf("请依次输入俩个值(中间用逗号隔开）：\n");
	scanf("%f %f %f",&a,&b);
	sides_triangle[0]=a;
	sides_triangle[1]=b;
	for(int i = 0,temp=0;i<2;i++)
	{
		temp=temp+sides_triangle[i];
	}
	printf("三角形的周长为%f",temp);
	
	return 0;
 } 

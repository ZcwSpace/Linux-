#include <stdio.h>
#define MAX 10000000

int main(void)
{
    int number,count=0;
    printf("请输入一个素数：");
    scanf("%d",&number);
    for(int i=1;i<=MAX;i++)
    {
        if(i%number==0)
        {
            count++;
        }
    }
    printf("%d以内能整除于%d的数字的数量为%d\n",MAX,number,count);
    count=0;
    printf("请输入一个不是素数的数字：");
    scanf("%d",&number);
    for(int i=1;i<=MAX;i++)
    {
        if(i%number==0)
        {
            count++;
        }
    }
    printf("%d以内能整除于%d的数字的数量为%d\n",MAX,number,count);

    return 0;
}
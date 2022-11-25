#include <stdio.h>
#define LENGTH 5

int main(void)
{
    int num[LENGTH],temp;

    //输入数据
    for(int i=0;i<LENGTH;i++)
    {
        scanf("%d",&num[i]);
    }

    //冒泡排序
    for(int i=0;i<LENGTH-1;i++)
    {
        for(int j=0;j<LENGTH-1-i;j++)
        {
            if(num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }

    //输出数据
    for(int i=0;i<LENGTH;i++)
    {
        printf("%d ",num[i]);
    }
    putchar('\n');

    return 0;
}
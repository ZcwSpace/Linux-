#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5

void finding_data(int b[5],int data);

int main(void)
{
    int a[LENGTH],data;

    for(int i=0;i<LENGTH;i++)
    {
        printf("请输入第%d个数据：",i+1);
        scanf("%d",&a[i]);
    }
    printf("请输入想要查找的数字:");
    scanf("%d",&data);
    finding_data(a,data);

    return 0;
}
void finding_data(int b[LENGTH],int data)
{
    if(data<b[0]||data>b[LENGTH-1])
    {
        printf("要查找的数据不在输入的数据内！\n");
        
        exit(-1);
    }

    int middle,last,first;

    first=0;
    last=LENGTH-1;
    while(1)
    {
        middle=(first+last)/2;
        
        if(data==b[middle])
        { 
            printf("要寻找的的数据是%d\n",b[middle]);
            break;
        }
        else if(last<=first)
        {
            printf("没找到数据\n");
            break;
        }
        else if(data<b[middle])
        {
           last=middle-1;
        }
        else if(data>b[middle])
        {
            first=middle+1;
        }
    }
}
    

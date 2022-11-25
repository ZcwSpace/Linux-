#include <stdio.h>

#define LENG 10

void sorting(int i,int j,int *num);

int main()
{
    int num[LENG];

    for(int i=0;i<LENG;i++)
    {
        printf("请输入第%d个数据：",i+1);
        scanf("%d",&num[i]);
    }
    putchar('\n');
    putchar('\n');

    printf("您输入的数据为：\n");

    for(int i=0;i<LENG;i++)
    {
        printf("%d ",num[i]);
    }
    putchar('\n');
    putchar('\n');

    sorting(0,LENG-1,num);

    printf("您输出的数据为：\n");

    for(int i=0;i<LENG;i++)
    {
        printf("%d ",num[i]);
    }
    putchar('\n');
    putchar('\n');


    return 0;
}
void sorting(int i,int j,int *num)
{
    if(j>i)
    {
        int pivot,temp,tempi,tempj;

        pivot=num[i+(j-i)/2];
        tempi=i;
        tempj=j;
        
        while(tempj>=tempi)
        {
            while(num[tempi]<pivot)
            {
                tempi++;
            }

            while(num[tempj]>pivot)
            {
                tempj--;
            }

            if(tempi<=tempj)
            {
                temp=num[tempi];
                num[tempi]=num[tempj];
                num[tempj]=temp;
                tempi++;
                tempj--;
            }
            
        }
        sorting(i,tempj,num);
        sorting(tempi,j,num);
    }
}
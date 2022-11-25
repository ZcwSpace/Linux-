#include <stdio.h>
#include <stdlib.h>

int judging(int a[9]);

int main()
{
    int a[9]={0,7,8,6,4,5,3,2,1};

    printf("%d ",judging(a));


    return 0;
} 
int judging(int a[9]) 
{
    int temp[8];

    for(int i=0;i<8;i++)
    {
        temp[i]=8-i;
    }

    int count;
    for(int i=0;i<9;i++)
    {
        for(count=0;temp[count]==a[i]&&count!=8;)
        {
            count++;
            if(i==8)
            {
                i=0;
            }
            else
            {
                i++;
            }
        }
        if(count==8)
        {
            return 1;
        }
        else if(count!=0)
        {
            return 0;
        }
    }
}
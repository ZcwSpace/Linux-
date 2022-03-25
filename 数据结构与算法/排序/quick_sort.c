#include <stdio.h>
#define LENGTH 6

void quick_sort(int array[],int first,int last);

int main(void)
{
    int array[LENGTH];

    for(int i=0;i<LENGTH;i++)
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&array[i]);
    }

    quick_sort(array,0,LENGTH-1);

    printf("排序后的数据为：");
    for(int i=0;i<LENGTH;i++)
    {
        printf("%d ",array[i]);
    }
    putchar('\n');

    return 0;
}
void quick_sort(int array[],int left,int right)
{
    int i=left,j=right,point,temp;

    //point=array[(left+right)/2];//point只是一个基点，用来将array[left]和array[right]之间的数分成大于point和小于point的两部分数。
    point=array[i];
    while(i<=j)
    {
        while(array[i]<point)
        {
            i++;
        }
        while(array[j]>point)
        {
            j--;
        }
        if(i<=j)
        {
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
            i++;
            j--;
        }
    }
    if(left<j)
    {
        quick_sort(array,left,j);
    }
    if(right>i)
    {
        quick_sort(array,i,right);
    }
}
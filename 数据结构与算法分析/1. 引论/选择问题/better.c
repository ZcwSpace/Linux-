//设有一组数N个数而要确定其中第k个最大者。我们称之为选择问题。
/*把前k个元素读入数组并以（从大到小的顺序）。接着，将剩下的元素再逐个读入。
当读取新元素时，如果它小于数组中的第k个元素则忽略，否则就将其放到数组中，正确的位置上，同时将数组中的一个元素挤出数组。、
当算法终止时，位于第k个位置上的元素作为答案返回。*/
#include <stdio.h>
#define k 5
#define MAXSIZE 10

void selection_sorting(int nums[]);
void inserting__data(int nums[],int temp);
int getting_addr(int nums[],int temp);

int main(void)
{
    int nums[k]={0};
    
    //依次输入前k个数据
    for(int i=0;i<k;i++)
    {
        printf("请输入第%d个数字：",i+1);
        scanf("%d",&nums[i]);
    }
    
    //对输入的前k个数据按由大到小排序
    selection_sorting(nums);

    int temp,addr;
    //继续输入后面的数据
    for(int i=k;i<MAXSIZE;i++)
    {
        printf("请输入第%d个数字：",i+1);
        scanf("%d",&temp);
        //判断后面的数据是否大于第k大的数据
        if(temp>nums[k-1])
        {
            inserting__data(nums,temp);
        }
    }
    //输出处理完后面的数据后的前k个数据
    for(int i=0;i<k;i++)
    {
        printf("%d ",nums[i]);
    }
    putchar('\n');
    
    //输出第k大的数据
    printf("第%d大的元素为%d",k,nums[k-1]);

    return 0;
}

//对数组内的数据进行选择排序
void selection_sorting(int nums[])
{
    int temp;

	for(int i=0;i<5-1;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			if(nums[i]<nums[j])
			{
				temp=nums[i];
				nums[i]=nums[j];
				nums[j]=temp;
			}
		}
	}
}
//将大于第k大的数据插入到数组内，并挤出第k大的数据
void inserting__data(int nums[],int temp)
{
    int addr;
    
    addr=getting_addr(nums,temp);
    //将要插入的位置插入到数组中合适的位置，并挤出第k大的数据
    if(addr==k)
    {
        nums[addr-1]=temp;
    }
    else
    {
        for(int i=k-2;i>=addr-1;i--)
        {
            nums[i+1]=nums[i];
        }
        nums[addr-1]=temp;
    }
}

//获取要插入的位置
int getting_addr(int nums[],int temp)
{
    int addr;

    addr=k;
    for(int i=0;i<k-1;i++)
    {
        if(temp>=nums[i])
        {
            addr=i+1;
            break;
        }
    }

    return addr;
}
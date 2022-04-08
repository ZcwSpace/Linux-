//设有一组数N个数而要确定其中第k个最大者。我们称之为选择问题。
//将这N个数读进一个数组中，再通过某种简单的算法以递减顺序将数组排序，然后返回k上的元素。
#include <stdio.h>

void selection_sorting(int nums[]);

int main(void)
{
    int nums[5]={0},ranking;
    
    //依次输入5个数据
    for(int i=0;i<5;i++)
    {
        printf("请输入第%d个数字：",i+1);
        scanf("%d",&nums[i]);
    }
    
    //对输入的数据进行选择排序
    selection_sorting(nums);
    
    //输入想要查找的第几大的数字
    printf("您要查找第几大的数字？");
    scanf("%d",&ranking);
    printf("您要查找第%d大的数字为%d\n",ranking,nums[ranking-1]);

    return 0;
}
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
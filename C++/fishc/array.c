//对一个整形数组求和，定义一个存储着n个元素的数组，要求用C语言完成这个任务。
#include <stdio.h>

const int num = 10;

void getting_sum(int *arry);

int main()
{
    int arry[num];

    for(int i=0;i<num;i++)
    {
        arry[i]=i;
    }

    int size=sizeof(arry)/sizeof(arry[0]);

    printf("arry = %d\n",size);
    getting_sum(arry);
    

    return 0;
}

void getting_sum(int *arry)//为节省传输量，所以仅传输地址。
{
    int sum = 0;
    int size=sizeof(arry);

    printf("arry = %d\n",size);
    for(int i=0;i<num;i++)
    {
        sum+=arry[i];
    }

    printf("数组的和 = %d\n",sum);

}
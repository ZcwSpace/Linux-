#include <stdio.h>

int main()
{
    int i,j;
    double temp,a[10];

    //输入十个数
    printf("请输入十个整数：\n");
    for(i=0;i<10;i++)
    {
        scanf("%lf",&a[i]);
    }
    //排序
    for(i=1;i<10;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[j+1]>a[j])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
            else
            {
                break;
            }
        }
    }

    //输出数据
    for(i=0;i<10;i++)
    {
        printf("%lf ",a[i]);
    }
    putchar('\n');

    return 0;
}
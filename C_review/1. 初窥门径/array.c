#include <stdio.h>

int main(void)
{
    int a[5]={[2]=1,[3]=2};//0 0 1 2 0
    int b[2][2]={[1][0]=1};//0 0 1 0

    for(int i=0;i<5;i++)
    {
        printf("%d\n",a[i]);
    }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
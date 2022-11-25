#include <stdio.h>

int main ()
{
    int a[4],t,i,j;

    for(i=0;i<4;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<4;i++)
    {
        for(j=1;j<4;j++)
        {
            if(a[i+1]>a[i])
            {
                t=a[i+1];
                a[i+1]=a[i];
                a[i]=t;
            }
        }
        printf("%d ",a[i]);

    }
}
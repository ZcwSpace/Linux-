#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //开辟3*2的二维数组
    int (*p)[2] = (int (*)[2])malloc(3*2*sizeof(int));
    memset((void *)p, 0, 3*2*sizeof(int)); //保险起见，我们将空间清零

    //赋值
    int i=0, j=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
                *(*(p+i)+j) = i + j;
        }
    }

    //输出
    i=0; j=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
                printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    
    //释放数组空间
    free(p);
    
    return 0;
}
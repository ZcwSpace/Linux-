#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //开辟有3个元素的一维数组
    int *p = (int *)malloc(3*sizeof(int));
    //memset((void *)p, 0, 3*sizeof(int)); //保险起见，我们将空间清零
    bzero(p, 3 * sizeof(int));//使用bzero也可以

    //赋值
    int i=0, j=0;
    
    for(i=0; i<3; i++)
    {
        *(p+i) = i;
    }
    
    //输出
    i=0;

    for(i=0; i<3; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    
    //释放数组空间
    free(p);
    
    return 0;
}	
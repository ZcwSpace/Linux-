#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //开辟3*2*2的三维数组
    int (*p)[2][2] = (int (*)[2][2])malloc(3*2*2*sizeof(int));
    memset((void *)p, 0, 3*2*2*sizeof(int)); //保险起见，我们将空间清零
    
    int i=0, j=0, k=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            for(k=0; k<2; k++)
            {
                *(*(*(p+i)+j)+k) = i + j + k;
                //p[i][j][k] = i + j + k;
            }
        }
    }
    i=0; j=0; k=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            for(k=0; k<2; k++)
            {
                    printf("%d ", p[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    free(p);
    
    return 0;
}
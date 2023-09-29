//创建一个4*3的新形式的二维数组
#include <stdio.h>
	
int main(void)
{
    int i = 0, j = 0;
    int **p = NULL;
    
    p = (int **)malloc(4*sizeof(int *));
    if(NULL != p)
    {
        for(i=0; i<4; i++)
        {
            *(p+i) = malloc(3*sizeof(int));
        }
    }
    
    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            *(*(p+i)+j) = i+j;
        }
    }
    
    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ", *(*(p+i)+j)); //p[i][j]
        }
        printf("\n");
    }

    //释放空间
    for(j=0; j<3; j++)
	{
		free(*(p+i));
	}	
	free(p);
    
    return 0;
}		
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int * ptr=NULL;
    int num,count=0;

    do   
    {
        printf("请输入数据（输入-1结束录入）:");
        scanf("%d",&num);
        count++;
        ptr=realloc(ptr,count*4);
        if(ptr==NULL)
        {
            printf("malloc调用失败\n");
        }
        *(ptr+count-1)=num;
    } while (num!=-1);
    
    for(int i=0;i<count;i++)
    {
        printf("%d ",ptr[i]);
    }
    putchar('\n');
    free(ptr);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int * ptr;
    int num;

    printf("请输入要录入整数的个数：");
    scanf("%d",&num);

    ptr=malloc(num*4);
    if(ptr==NULL)
    {
        printf("malloc调用失败\n");
    }
    for(int i=0;i<num;i++)
    {
        printf("请输入第%d个整数：",i+1);
        scanf("%d",ptr+i);
    }

    for(int i=0;i<num;i++)
    {
        printf("%d\n",ptr[i]);
    }
    free(ptr);//局部变量不允许手动释放

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int * ptr;
    int num=5;

    ptr=malloc(4);

    if(ptr==NULL)
    {
        printf("malloc调用失败\n");
    }
    printf("请输入一个整数：");
    scanf("%d",ptr);
    printf("%d\n",*ptr);

    ptr=&num;
    printf("请输入一个整数：");
    scanf("%d",ptr);
    printf("%d\n",*ptr);
    free(ptr);//局部变量不允许手动释放

    return 0;
}
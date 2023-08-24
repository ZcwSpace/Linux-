#include <stdio.h>

int main ()
{
    int a, b, ret;

    while(1)
    {
        printf("scanf的格式为：scanf(\"%d %d\", &a, &b);\n");
        printf("请输入a和b的值：");
        ret = scanf("%d %d", &a, &b);
        getchar();
        switch(ret)
        {
            case 2 :
            printf("输入正确！\n");
            break;
            case 1:
            printf("有些输入格式错误！\n");
            break;
            case 0:
            printf("所有的输入格式错误！\n");
            break;  
            case -1:
            printf("scanf函数发生了错误！\n");
            break;      
        }
        putchar('\n');
    }
   
    return 0;
}
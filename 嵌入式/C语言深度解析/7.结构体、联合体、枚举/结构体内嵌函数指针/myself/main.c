#include <stdio.h>
#include "stu.h"
#include "tea.h"
#include "public.h"

#define STUNUM 2
#define TEANUM 3

Stu stu[STUNUM] = {
    {1, "郑超文", 56},
    {2, "陈龙", 55}
};

Tea tea[TEANUM] = {
    {1, "张然", 4000},
    {2, "姚倩", 4000},
    {3, "朱瑜馨", 6000}
};

int main()
{
    int n = 0;
    
    while(1)
    {
        printf("请选择操作对象：\n");
        printf("1.学生\n");
        printf("2.老师\n");
        scanf("%d", &n);
        if(1 == n)
        {
            initing_stu(STUNUM, (char *)stu);
        }
        else if(2 == n)
        {
            initing_stu(TEANUM, (char *)tea);
        }
        else
        {
            printf("输入错误，请重新输入\n");
            continue;
        }
        while(1)
        {
            printf("请选择要进行的操作：\n");
            printf("1.显示所有数据\n");
            printf("2.修改数据\n");
            printf("3.退出本次操作\n");
            scanf("%d", &n);
            if(1 == n)
            {
                printing();
            }
            else if(2 == 1)
            {
                altering();
            }
            else if(3 == n)
            {
                break;
            }
            else
            {
                printf("输入错误，请重新输入\n");
            }
        }
    }
    return 0;
}
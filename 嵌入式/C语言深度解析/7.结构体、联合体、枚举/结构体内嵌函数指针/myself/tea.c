#include <stdio.h>
#include "tea.h"
#include "public.h"
void initing_tea(int n, char *tea)
{
    Pub pub;

    pub.arc = n;
    pub.arg = tea;
    pub.print = printing;
    pub.alter = altering;
    initing(pub);
}

static void printing_tea(int n , char *tea)
{
    int i =0;
    Tea *tea2 = (Tea *)tea;
    
    for(int i = 0; i < n; i++)
    {
        printf("%d %s %f\n", tea2[i].id, tea2[i].name, tea2[i].income);
    }
}

static void altering_tea(int n , char * tea)
{
    int i =0;
    int temp = 0;
    Tea *tea2 = (Tea *)tea;

    printf("请输入要修改的成员的编号：");
    scanf("%d", &temp);

    for(i = 0; i < n; i++)
    {
        if(n == tea2[i].id)
        {
            printf("该成员原来的数据为：\n");
            printf("%d %s %f\n", tea2[i].id, tea2[i].name, tea2[i].income);
            printf("请输入新数据：");
            scanf("%d %s %f", &tea2[i].id, tea2[i].name, &tea2[i].income);
        }
    }
    if(i > n)
    {
        printf("该成员不存在，请重新输入！\n");
    }
}

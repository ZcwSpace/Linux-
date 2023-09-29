#include "public.h"
#include "stu.h"
#include <stdio.h>

void initing_stu(int n, char *stu)
{
    Pub pub;

    pub.arc = n;
    pub.arg = stu;
    pub.print = printing;
    pub.alter = altering;
    initing(pub);
}

static void printing_tea(int n , char *stu)
{
    int i =0;
    Stu *stu2 = (Stu *)stu;
    
    for(int i = 0; i < n; i++)
    {
        printf("%d %s %f\n", stu2[i].id, stu2[i].name, stu2[i].score);
    }
}

static void altering_tea(int n , char * stu)
{
    int i =0;
    int temp = 0;
    Stu *stu2 = (Stu *)stu;

    printf("请输入要修改的成员的学号：");
    scanf("%d", &temp);

    for(i = 0; i < n; i++)
    {
        if(n == stu2[i].id)
        {
            printf("该成员原来的数据为：\n");
            printf("%d %s %f\n", stu2[i].id, stu2[i].name, stu2[i].score);
            printf("请输入新数据：");
            scanf("%d %s %f", &stu2[i].id, stu2[i].name, &stu2[i].score);
        }
    }
    if(i > n)
    {
        printf("该成员不存在，请重新输入！\n");
    }
}

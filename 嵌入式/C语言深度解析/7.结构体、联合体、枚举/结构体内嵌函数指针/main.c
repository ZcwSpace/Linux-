#include <stdio.h>
#include "public.h"     //公共代码的.h
#include "stu.h"        //差异代码---操作学生信息代码的.h
#include "tea.h"        //差异代码---操作老师信息代码的.h 

#define STUNUM 6        //学生结构体数组的元素个数
#define TEANUM 7        //老师结构体数组的元素个数

/* 存放"学生"数据的结构体数组  */
Stu stu[STUNUM] = {
    {"张  三", 1, 65.0},
    {"李  四", 2, 34.5},
    {"李  雪", 3, 99.5},
    {"宋  朋", 4, 75.0},
    {"黄明明", 5, 60.5},
    {"周  华", 6, 85.5},
};

/* 存放"老师"数据的结构体数组  */
Tea tea[TEANUM] = {
    {"黄  蓉", 1, 1},
    {"杨  康", 2, 4},
    {"周伯通", 3, 6},
    {"郭  靖", 4, 6},
    {"欧阳锋", 5, 8},
    {"杨  过", 6, 2},
    {"吴  邪", 6, 2},
};

/* 主函数 */
int main(void)
{
    int select = 0;  //操作选择

    while(1)
    {
        printf("1. 操作学生\n");
        printf("2. 操作老师\n");
        scanf("%d", &select);

        if(1 == select)
                Stu_initFun(STUNUM, stu); //初始化学生的操作
        else if(2 == select)
                Tea_initFun(TEANUM, tea); //初始化老师的操作

        /* 选择初始化的谁,具体操作的就是谁 */
        while(1)
        {
                printf("1. 显示信息\n");
                printf("2. 修改信息\n");
                printf("3. 重新选择操作对象\n");
                scanf("%d", &select);

                if(1 == select) printFun();      //打印信息
                else if(2 == select) alterFun(); //修改信息
                else if(3 == select) break;
                else printf("无此选项\n");
        }

    }

    return 0;
}
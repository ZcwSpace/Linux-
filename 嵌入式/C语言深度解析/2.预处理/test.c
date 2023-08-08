#include <stdio.h>

int main()
{
    printf("预编译的日期：%s\n", __DATE__);
    printf("预编译的文件：%s\n", __FILE__);
    printf("当前行所在行号：%d\n", __LINE__);
    printf("预编译的时间：%s\n", __TIME__);
    printf("当前所在函数：%s\n", __func__);

    return 0;
}
#include <stdio.h>
#include <stdarg.h>

int sum(int n,...);

int main(void)
{
    int result;

    result=sum(5,1,2,3,5,11);
    printf("result=%d\n",result);

    return 0;
}

// 参数的个数 参数1 参数2 ...
int sum(int n,...)//三个小点可以理解为省略号，表示输入的参数个数不确定
{
    int sum=0;
    va_list vap;//定义参数列表
    va_start(vap,n);//初始化参数列表，n是参数的个数
    
    for(int i=0;i<n;i++)
    {
        sum+=va_arg(vap,int);//获取参数值
    }
    va_end(vap);//关闭参数列表

    return sum;
}
#include <stdio.h>		
#include "calculate.h"  //包含静态库的头文件
#include <dlfcn.h>

int main(void)
{
    double a = 10.5;
    double b = 20.6;
    double ret = 0;
    void * handle = NULL;
    double (*funp)() = NULL;

    //加载动态库到内存中
    handle = dlopen("./libcalculate.so", RTLD_NOW);
    if(NULL == handle)
    {
        printf("加载动态库到内存中失败！\n");
    }

    funp = (double (*)())dlsym(handle, "add");
    ret = funp(a, b); //加
    printf("add: ret = %f\n", ret);

    funp = (double (*)())dlsym(handle, "sub");
    ret = funp(a, b); //减
    printf("sub: ret = %f\n", ret);

    funp = (double (*)())dlsym(handle, "mul");
    ret = funp(a, b); //乘
    printf("mul: ret = %f\n", ret);
    
    funp = (double (*)())dlsym(handle, "div");
    ret = funp(a, b);//除
    printf("div: ret = %f\n", ret);

    funp = (double (*)())dlsym(handle, "power");
    ret = funp(a);//平方  
    printf("power: ret = %f\n", ret);

    //从内存中删除动态库
    if(0 != dlclose(handle))
    {
        printf("从内存中删除动态库失败！\n");
    }

    return 0;
}
#include <stdio.h>
#include <time.h> 			//time函数所需的头文件

int main(void)
{
    register int a = 0; 	//寄存器局部变量
    int b = 0; 						//自动局部变量(栈)
    int old_time = 0; 
    
    old_time = time(NULL);				//记录循环开始时的时刻

    for(a=0; a<1000000000; a++); 	//循环累加a的值，实现延时

    printf("%ld\n", time(NULL)-old_time); //延时时间 = 结束时刻-其实时刻


    old_time = time(NULL); 				//起始时刻

    for(b=0; b<1000000000; b++); 	//延时

    printf("%ld\n", time(NULL)-old_time); //延时时间

    return 0;
}
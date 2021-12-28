#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void test();

int main(void)
{
    //printf("!!!!!!!!!!");//不输出

    //printf("hello world\n");//满足行缓存，输出

    //printf("cajkabcjkab");
    //fflush(stdout);//刷新标准输出的库缓存

    //printf("cajkabcjkab");
    //fclose(stdout);

    printf("5645556");
    //exit(-1);
    //return 0;
    //_exit(-1);
    test();
    while(1)
    {

    }

    //return 0;    
}
void test()
{
    printf("test");
    return;
}
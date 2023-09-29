#include <stdio.h>
#include <stdlib.h>
			
//出错处理函数
void print_error(char *file, int line, char *str)
{
        //报告错误的位置
        fprintf(stderr, "File %s, Line %d, Function %s error\n", file, line, str);
        perror("error Reason"); //打印函数出错的原因
        exit(-1); //终止进程，说白了就是终止整个程序
}

int fun(int **p, long size)
{
        *p = malloc(size);
        //如果malloc返回NULL，就说明错了，需要报函数错误
        if(NULL == *p) 
        {
            print_error(__FILE__, __LINE__ - 4, "malloc");
        }
}

int main(void)
{
        int ret = 0;
        int *p = 0;
        long size = sizeof(int)*4000000000000000000; 
        
        ret = fun(&p, size);
        
        return 0;
}
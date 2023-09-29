#include <stdio.h>   //fprintf所需的.h
#include <string.h>  //strerror所需的.h
#include <errno.h>   //全局变量errno所在的头文件
#include <stdlib.h>

int main(void)
{
        FILE * p= fopen(".\\file.txt", "t");//后面这个参数写法错了
        if(NULL == p)
        {	
            //strerror会将errno中的错误号翻译为字符串
            fprintf(stderr, "fopen error：%s\n", strerror(errno)); 
            exit(-1); //直接终止进程
        }

        return 0;
}
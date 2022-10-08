#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;

    int ch;

    //打开文件
    if(NULL==(file=fopen("hello.txt","r")))
    {
        printf("打开失败！！！\n");
        exit(EXIT_FAILURE);
    }

    //读出文件里的数据
    while((ch=getc(file))!=EOF)
    {
        putchar(ch);
    }
    putchar('\n');
    fclose(file);

    return 0;
}
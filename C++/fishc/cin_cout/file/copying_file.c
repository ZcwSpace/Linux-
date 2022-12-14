#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[])//参数的个数 参数（参数之间以空格间隔）
{
    FILE *read,*write;
    int letter;

    if(argc!=3)
    {
        fprintf(stderr,"输入形式：copyFile 源文件名 目标文件名 \n");
        exit(EXIT_FAILURE);
    }

    if(NULL == (read=fopen(argv[1],"r")))
    {
        fprintf(stderr,"打不开文件：%s \n",argv[1]);
        exit(EXIT_FAILURE);   
    }

    if(NULL == (write=fopen(argv[2],"w")))
    {
        fprintf(stderr,"打不开文件：%s \n",argv[2]);
        fclose(read);
        exit(EXIT_FAILURE);   
    }


    while((letter=getc(read))!=EOF)
    {    
        //EOF：end of file，等于-1.
        //get在遇到文件结束或者遇到错误会返回-1,getc返回的文件类型为整形
        if(putc(letter,write)==EOF)
        {
            break;
        }   
    }
    if(ferror(in))
    {
        printf("读取文件 %s 失败！\n",argv[1]);
    }
    if(ferror(out))
    {
        printf("写入文件 %s 失败！\n",argv[1]);
    }

    printf("成功复制一个文件！\n”);

    fclose(read);
    fclose(write);

    return 0;
}
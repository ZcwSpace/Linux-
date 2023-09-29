#include <stdio.h>
#include <stdlib.h>
#include <string.h>
			
#define print_error(str) \
do{\
    fprintf(stderr, "File %s, Line %d, Function %s error\n", __FILE__, __LINE__, str);\
    perror("error Reason");\
    exit(-1);\
}while(0);

int main()
{
    FILE *fp = NULL;
    
    fp = fopen("./test.txt", "r+"); 								//Linux
    //fp = fopen("C:\\Users\\Administrator\\Desktop\\file.txt", "r"); //whindows
    if(NULL == fp) print_error("fopen");
    
    printf("%p\n", fp); 

    //写入数据
    if(0 > fprintf(stderr, "12"))//会覆盖文件中原有的数据，写入几个覆盖几个
    {
        print_error("fprintf");
    }
    
    //while(1);

    fclose(fp);

    return 0;
}
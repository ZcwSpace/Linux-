#include <stdio.h>
#include <string.h>
#include <stdlib.h>
		
#define print_error(str) 	\
do{	\
    fprintf(stderr, "File %s, Line %d, Function %s error\n", __FILE__, __LINE__, str);\
    perror("error Reason");	\
    exit(-1);	\
}while(0);

int main()
{
    int ret = 0;
    FILE *fp = NULL;

    //fp = fopen("/home/zxf/Desktop/file.txt", "r"); 									//Linux
    fp = fopen("./test.txt", "r"); 	//whindows
    if(NULL == fp) print_error("fopen")

    char buf[10] = {0};
    while(1)
    {
            if(feof(fp) != 0)
            {
                    printf("文件末尾");
                    break;
            }
            fgets(buf, sizeof(buf), fp);
            printf("%s\n", buf);
            memset(buf, 0, sizeof(buf));
    }
    fclose(fp);

    return 0;
}
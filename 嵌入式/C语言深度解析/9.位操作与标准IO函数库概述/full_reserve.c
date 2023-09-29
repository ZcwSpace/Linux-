#include <stdio.h>
			
int main()
{
    FILE *fp = NULL;

    fp = fopen("./test.txt", "w+"); 						//Linux
    //p = fopen("C:\\Users\\Administrator\\Desktop\\file.txt", "w+"); //whindows

    fprintf(fp, "hello world\n");

    fflush(fp);

    while(1);

    fclose(fp);

    return 0;
}
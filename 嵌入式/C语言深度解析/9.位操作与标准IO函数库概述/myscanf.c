//模拟一个myscanf函数，在myscanf函数中调用fgets来从stdin获取字符串，然后按照
//%d、%f等格式的要求，将字符串数据转为整形、浮点等。
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int myscanf(char * str, ...);

int main()
{
    int a, b, c;
    myscanf("%d %f %c", &a, &b, &c);

    return 0;
}

int myscanf(char * str, ...)
{
    char *temp = NULL;
    va_list ap;

    va_start(ap, str);
    fgets(temp,sizeof(str), stdin);

    for(int i = 0; i < strlen(str); i++)
    {
        if('%' == str[i])
        {
            switch(str[i + 1])
            {
                case 'd':
                //*(ap) = *(int *)(temp + i);
                printf("%d\n", *((int *)(temp+i)));
                va_arg(ap, int);
                break;
                
                case 'f':
                //*(ap) = *(float *)(temp + i);
                printf("%d\n", *((float *)(temp + i)));
                va_arg(ap, double);
                break;
                
                case 'c':
                printf("%d\n", *((char *)(temp + i)));
                //*(ap) = *(char *)(temp + i);
                va_arg(ap, int);
            }
        }
    } 
    va_end(ap);
}
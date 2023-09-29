#include <stdio.h>

int main(void)
{
    char *p = "hello"; 

    int i = 0;
    for(i=0; p[i]!='\0'; i++)
    {
        //printf("%c\n", p[i]); //等价于*(p+i)
        printf("%c\n", "hello"[i]);
    }
    
    return 0;
}
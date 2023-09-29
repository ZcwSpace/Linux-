#include <stdio.h>

int main()
{
    unsigned int a = 6;

    int b = -10;

    if((a+b) > 6)
    {
        printf(" > \n");
        if((a+b) == (unsigned int)-6)
        {
            printf("==");
        }
    }	
    else 
    {
        printf(" < \n");
    }

    return 0;
}
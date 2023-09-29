#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;

    fputc('a', stdin);

    scanf("%c", &a);

    printf("%c", a);
    
}
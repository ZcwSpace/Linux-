#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long a = 100;
static int b = 100;
int c;

int main(void)
{
    time(&a);
    printf("hello world\n");

    return 0;
}
#include <stdio.h>

void printing_array(int b[1]);

int main(void)
{
    int a[1]={0};

    printf("a:%d\n",a[0]);

    printing_array(a);

    printf("a:%d\n",a[0]);

    return 0;
}
void printing_array(int b[1])
{
    b[0]=2;
    printf("b:%d\n",b[0]);
}
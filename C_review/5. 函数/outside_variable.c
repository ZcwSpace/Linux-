#include <stdio.h>

int a=5;
void b();

int main(void)
{
    int a=6;
    printf("a=%d in main\n",a);
    b();

    return 0;
}
void b()
{
    printf("a=%d in b\n",a);

}
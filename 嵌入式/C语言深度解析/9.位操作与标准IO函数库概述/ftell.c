#include <stdio.h>

int main()
{
    fseek(stdout, 10, SEEK_END);
    rewind(stdin);
    ftell(stderr);

    return 0;
}
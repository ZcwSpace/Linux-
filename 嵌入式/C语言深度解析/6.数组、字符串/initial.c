#include <stdio.h>

int main()
{
    int buf[2][2] = {};

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d ", buf[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

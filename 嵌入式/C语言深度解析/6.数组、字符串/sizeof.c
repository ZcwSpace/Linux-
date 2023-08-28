#include <stdio.h>

int main()
{
    //int buf[5];
    int buf[5] = {[0] = 5,[3] = 6};

    //printf("%d", sizeof(buf));
    printf("buf = %p, &buf = %p\n", buf, &buf);
    printf("buf + 1 = %p, &buf +1 = %p\n", buf + 1, &buf + 1);
    //fun(&buf);

    return 0;
}

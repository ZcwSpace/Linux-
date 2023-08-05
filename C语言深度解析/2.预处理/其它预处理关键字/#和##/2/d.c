#include <stdio.h>

#define TAG1 info
#define TAG2 _teacher

#define STRUCT(a, b) struct a##b
#define _STRUCT(a,b) STRUCT(a, b)

_STRUCT(TAG1, TAG2)
{
        int num;
};

int main(void)
{

    return 0;
}
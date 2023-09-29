#include <stdio.h>

typedef int *intp;
const intp p; 
intp const p1;
//以上这两种都等价于int *const p;
typedef int const *cstIntp;
cstIntp p2;

int main()
{
    int a;
    p = a;
    p1 = a;
    p2 = a;


    return 0;
}
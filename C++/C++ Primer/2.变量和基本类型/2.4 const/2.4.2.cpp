#include <iostream>

int main()
{
    //int i = -1, &r = 0;
    //int i2;
    /*
    int *const p2 = &i2;
    */
    //const int i = -1, &r = 0;
    //const int * const p3 = &i2;
    //const int *p1 = &i2;
    //const int &const r2;
    //const int i2 = i, &r = i;
/*
    int i, *const cp = &i;
    int *p1, *const p2 = p1;
    const int ic = i, &r = ic;
    const int *const p3 = &ic;
    const int *p;

    i = ic;
    p1 = p3;
    p1 = &ic;
    p3 = &ic;
    p2 = p1;
    ic = *p3;
*/
    const int v2 = 0;
    int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = &v2, &r2 = v2;

    p2 = &v1;
    *p2 = 5;

    p3 = &v1;
    *p3 = 5;

    return 0;
}
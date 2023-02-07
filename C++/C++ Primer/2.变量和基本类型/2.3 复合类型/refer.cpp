#include <iostream>

int main()
{
    //int ival = 1.01;

    /*
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    r2 = 3.14159;
    r2 = r1;
    i = r2;
    r1 = d;
    */
    int i, &ri = i;

    i = 5;
    ri = 10;
    std::cout << i << " " << ri << std::endl;

    return 0;
}
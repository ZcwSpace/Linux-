#include <iostream>

int main()
{
    /*
    int i = 0, &r = i;
    auto a = r;
    
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;

    auto &g = ci;

    a = 42;
    b = 42;
    c = 42;
    d = 42;
    e = 42;
    g = 42;
    */

   
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    return 0;
}
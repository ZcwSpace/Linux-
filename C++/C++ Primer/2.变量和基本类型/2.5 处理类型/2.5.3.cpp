#include <iostream>

int main()
{
    /*
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;

    std::cout << a << b << c << d << std::endl;
    */

    /*
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a; 
*/
    int a = 5;
    const int b = a;

    decltype (a) c ;
    auto d = a;

    decltype (b) e = b;
    auto f = b;
    
    
    return 0;
}
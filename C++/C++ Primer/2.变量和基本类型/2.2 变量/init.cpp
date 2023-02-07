#include <iostream>

int main()
{
    int unit_sold1 = 0;
    int unit_sold2={0};
    int unit_sold3{0};
    int unit_sold4(0);


    long double ld = 3.1415926536;
    int a{ld}, b = {ld};//转换未执行，因为存在丢失信息的危险
    int c(ld), d = ld;//转换正确执行，但也丢失了信息。


    return 0;
}
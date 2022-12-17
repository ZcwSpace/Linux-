//利用重载函数的方法设计一个程序，该程序通过函数“calc()”进行计算并返回显示结果
    //当传入一个参数时，计算该参数的平方值；
    //当传入两个参数时，计算两个参数的积；
    //当传入三个参数时，计算三个参数的和。
#include <iostream>

double calc(double parameter);
double calc(double parameter1,double paramater2);
double calc(double parameter1,double paramater2,double paramater3);

int main()
{
    using namespace std;


    cout << calc(2) << endl;
    cout << calc(2,2) << endl;
    cout << calc(2,2,2) << endl;

    return 0;
}

double calc(double parameter)
{
    return parameter*parameter;
}

double calc(double parameter1,double paramater2)
{
    return parameter1*paramater2; 
}

double calc(double parameter1,double paramater2,double paramater3)
{
    return parameter1+paramater2+paramater3;
}

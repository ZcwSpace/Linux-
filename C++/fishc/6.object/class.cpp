#include <iostream>

using namespace std;

class Car
{
public://作用域
    string color;
    string engine;
    float gas_tank;
    unsigned int Wheel;

    void fill_tank(float liter);//方法的声明
    void running(void);
};
void Car::fill_tank(float liter)//::作用域解析符：作用是告诉编译器这个方法属于哪个类
{
    if(liter+gas_tank>=200)
    {
        gas_tank=200;
    }
    else
    {
        gas_tank+=liter;
    }
}
int main()
{
    Car car;
    
    car.color="white";
    car.engine="8500";
    car.gas_tank=100;
    car.Wheel=4;

    return 0;
}
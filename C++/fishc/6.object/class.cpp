#include <iostream>

using namespace std;

class Car
{
public://作用域
    string color;
    string engine;
    float gas_tank=0;
    unsigned int wheel;
    unsigned int FULL_GAS=85;

    void setColor(string col);
    void setEngine(string eng);
    void setWheel(unsigned int whe);
    void fill_tank(float liter);//方法的声明
    float running(void);
};
void Car::fill_tank(float liter)//::作用域解析符：作用是告诉编译器这个方法属于哪个类
{
    gas_tank=liter;
}
void Car::setColor(string col)
{
    color=col;
}
void Car::setEngine(string eng)
{
    engine=eng;
}
void Car::setWheel(unsigned int whe)
{
    wheel=whe;
}
float Car::running(void)
{
    cout << "我当前正在以120 km/h的速度移动\n";
    gas_tank--;
    cout << "当前油量还剩" << 100*gas_tank/FULL_GAS << "%油量！\n";

    return 100*gas_tank/FULL_GAS;
}

int main()
{
    Car car;
    char i;
    
    car.setColor("white");
    car.setEngine("V8");
    car.setWheel(4);
    car.fill_tank(85);

    while(car.running())
    {
        if(car.gas_tank<10.0)
        {
            cout << "请问是否需要加满油再行驶(Y/N)：\n";
            cin >> i;
            if('Y' == i||'y' == i)
            {
                car.fill_tank(85);
            }
        }
    }

    return 0;
}
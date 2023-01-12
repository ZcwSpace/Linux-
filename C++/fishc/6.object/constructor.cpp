#include <iostream>
using namespace std;
/*
构造器的名字与它所在类的名字一样
系统在创建某个类的实例时会第一时间自动调用这个类的构造器。
构造器不会返回任何值
*/
 class Car
{
    Car(void);
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
Car::Car(void)//构造器就是对对象进行初始化
{
    color = "WHITE";
    engine="V8";
    wheel=4;
    gas_tank=FULL_GAS;
}
//函数重载在面向过程的语言里也可以实现。
//函数重载：用同样的名字再次定义一个有着不同参数但有着同样用途的函数。
//可以是参数个数上的不同，也可以是参数类型上的不同

//problem 2:编写一个温度转换程序，提示用户以【xx.x C】或【xx.x F】的格式输入
#include <iostream>

void converting(float temperature,char type);
void converting(int temperature,char type);

int main()
{
    using namespace std;
    
    float temperature;
    char type;

    cout << "请输入温度：（格式为：【xx.x C】或【xx.x F】）\n";

    cin >> temperature;
    cin >> type;
    //对输入的温度进行检查，温度不会太高，也不会太低
    converting(temperature,type);

    cout << "输入任何字符结束程序···";
    cin.ignore(1,'\n');
    cin.get();//从输入队列取一个字符

    return 0;
}

//输出浮点型温度
void converting(float temperature,char type)
{
    using namespace std;

    switch(type)
    {
        case 'C':
        case 'c':
            temperature=temperature*1.8+32;
            cout << temperature << " F\n"; 
            break;
        case 'F':
        case 'f':
            temperature=(temperature-32)/1.8;
            cout << temperature << " C\n";
            break;
        default:
            cout << "温度的类型输入错误，请输入华氏度(F)或者摄氏度(C)\n";
   }
}

//输出整形温度
void converting(int temperature,char type)
{
    using namespace std;

    switch(type)
    {
        case 'C':
        case 'c':
            temperature=temperature*1.8+32;
            cout << temperature << " F\n"; 
            break;
        case 'F':
        case 'f':
            temperature=(temperature-32)/1.8;
            cout << temperature << " C\n";
            break;
        default:
            cout << "温度的类型输入错误，请输入华氏度(F)或者摄氏度(C)\n";
   }   
}
//对函数进行重载，可以简化编程工作和提高代码可读性。
//重载并不是一个真正的面向对象的特征，它只是简化编程工作的一种方案，而简化工作正是C++等高级语言的全部追求。

/*
机器语言
C语言：面对过程 封装过程
面向对象：封装类
面向组件：封装程序
封装越高，运行越慢
*/

//不能随意重载，重载函数越多，程序越不容易看懂。
//要区分重载与覆盖。
    //覆盖：两个函数参数相同，函数名相同，返回值也相同。
//重载只能通过不同的参数重载，不能通过不同的返回值重载，尽管后者也可以用来区别函数。
//对函数进行重载的目的是为了方便对不同数据类型进行同样的处理。
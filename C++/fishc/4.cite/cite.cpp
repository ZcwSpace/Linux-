//如果事先就知道某个函数的参数只能接受一个地址，有没有一种约定使得在调用该函数时不需要使用指针的语法呢？
//引用和传址一样，都是把地址传递给函数，但语法不同更加容易了。

#include <iostream>
using namespace std;

void swap(int &x,int &y);//声明时指定我要接受的是一个整形变量的地址

int main()
{
    int x,y;

    cout << "请输入两个不同的值：";
    cin >> x >> y;

    swap(x,y);//编译器会自动将x、y的地址传过去

    cout << "调换后输出：" << x << ' ' << y << "\n\n";

    return 0;
}

void swap(int &x,int &y)
{
    int temp;

    temp=y;
    y=x;
    x=temp;
}
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    double result = sqrt(111);

    cout << "对111开方保留小数点后0~9位，结果如下：\n" << endl;

    //输出9次
    for(int i = 0;i <= 9;i++)
    {
        cout.precision(i);//控制输出的有效位数
        cout << result << endl;
    }
    cout << "当前的输出精度为：" << cout.precision() << endl;

    return 0;
}
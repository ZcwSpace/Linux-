//复杂==简单+简单。
//复杂：数组、指针和结构体。

//数组
//编程任务：定义一个可以容纳10个整数的数组，这些整数来自用户的输入。我们将计算这些值的累加和，平均值并输出。
#include <iostream>

int main()
{
    using namespace std;
    const  unsigned ITEM = 6;

    int array[ITEM];
    int sum=0;

    cout << "请输入" << ITEM << "个整形数据：\n\n";

    for(int i=0;i<ITEM;i++)
    {
        label:cout << "请输入第" << i+1 << "个整形数据：";
        /*
        while(!(cin >> array[i]))
        {
            cin.clear();//清楚掉错误状态。
            cin.ignore(100,'\n');
            cout << "\n请输入一个合法的值：";
        }*/
        if(!(cin >> array[i]))
        {
            i--;
            cin.ignore(2);
            goto label;
        }
        sum += array[i];
    }
    cout << "输入的" << ITEM << "数的和为：" << sum << endl;

    cout << "输入的" << ITEM << "个数的平均值为：" << (float)sum/ITEM << endl;

    return 0;
}
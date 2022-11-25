//对一个整形数组求和，定义一个存储着n个元素的数组，现在用C++语言完成这个任务。
#include <iostream>
using namespace std;
//用命名空间代替了.h
//C++标准库中所使用的所有标识符都在std中定义。
//命名空间的存在是为了避免混淆。如：queue.deleting()和tree.deleting();
//在不使用命名空间的情况下可以用如：命名空间名::名字的形式来使用，如：std::cout。

void getting_sum(int *arry);

const int num = 10;

int main()
{
    int arry[num];

    for(int i=0;i<num;i++)
    {
        arry[i]=i;
    }

    int size=sizeof(arry)/(sizeof(arry[0])*10);

    cout << "arry = " << size << endl;
    // console out:控制台输出；printf是一个函数，而cout是一个输出流对象
    //输出流：数据结构+索引。例如：从程序流向屏幕。
    //cout是属于basic_ostream类的对象。
    //basic_ostream在iostream头文件中被定义。

    //<<是重载的一种体现。
    //重载：按照不同的方式使用同一个操作符。
    

    getting_sum(arry);
    
    return 0;
}

void getting_sum(int *arry)//为节省传输量，所以仅传输地址。
{
    int sum = 0;
    int size=sizeof(arry);

    printf("arry = %d\n",size);
    for(int i=0;i<num;i++)
    {
        sum+=arry[i];
    }

    cout << "数组的和 = " << sum << endl;
}
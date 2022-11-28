#include <iostream>

int main()
{
    using namespace std;

    const int SIZE = 50;
    char buf[SIZE];

    cout << "请输入一段文本：";
    cin.read(buf,20);//从输入队列取出19个字符

    cout << "字符串搜集到的字符数为："
    << cin.gcount() << endl;//从输入队列取出的字符的个数

    cout << "输入的文本信息为：";
    cout.write(buf,20);
    cout << endl;

    return 0;
}
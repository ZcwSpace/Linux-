#include <iostream>

int main()
{
    using namespace std;

    char p;

    cout << "请输入一段文本：\n";

    while(cin.peek() != '\n')//查看输入队列的第一个是否是换行符
    {
        p = cin.get();//从输入队列取一个字符
        cout << p;
    }
    cout << endl;

    return 0;
}
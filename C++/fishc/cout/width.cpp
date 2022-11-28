#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    int width = 4;
    char str[20];

    cout << "请输入一段文本：\n";
    cin.width(5);//每次只接收4个字符,其他的放在流中等待接收。

    while(cin >> str)
    {
        cout.width(width++);
        cout << str << " " << width-1 << endl;
        cin.width(5);
    }//每次只输入4个字符，但输出个数依次递增，输入不够则左边补充空格

    return 0;
}
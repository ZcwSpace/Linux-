#include <iostream>

int main()
{
    using namespace std;

    char buf[20];

    cin.ignore(7);//忽略7个字符
    cin.getline(buf,10);//获得一行的9个字符到数组中

    cout << buf << endl;

    return 0;
}
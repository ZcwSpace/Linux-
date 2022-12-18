#include <iostream>

int main()
{
    using namespace std;
    const unsigned ITEM = 3;
    string str;

    //cin >> str;//不会输入空格
    getline(cin,str);
    cout << str << endl;   

    return 0;
}
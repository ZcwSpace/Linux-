#include <iostream>

int main()
{
    using namespace std;

    char str[5]="Fish";
    char * str_addr=str;

    for(int i=0;i<4;i++)
    {
        cout << *str_addr << "at ";
        cout << reinterpret_cast<unsigned long> (str_addr) << endl; 
        cout << str_addr << endl; 
        str_addr++;
    }

    return 0;
}
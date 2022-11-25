#include <iostream>
#include <climits>

int main()
{
    using namespace std;
    int n_int=INT_MAX;
    short n_short=SHRT_MAX;
    long n_long=LONG_MAX;
    long long n_llong=LLONG_MAX;

    cout << "int is " << sizeof(int) << " bytes.\n";
    cout << "short is " << sizeof n_short << " bytes.\n";
    cout << "long is " << sizeof n_long << " bytes.\n";
    cout << "long long is " << sizeof n_llong << " bytes.\n\n";

    cout << "Maximum values:\n";
    cout << "int : " << n_int << endl;
    cout << "short : " << n_short << endl;
    cout << "long : " << n_long << endl;
    cout << "long long : " << n_llong << endl << endl;

    cout << "Minimum int values = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;

    return 0;
}
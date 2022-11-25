#include <iostream>
#include <climits>
#define ZERO 0

int main()
{
    using namespace std;

    short sam=SHRT_MAX;
    unsigned short sue=sam;

    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited.\n" << "Add $1 to each account.\n" << "Now ";

    sam+=1;
    sue+=1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited.\n" << "Poor Sam!\n";

    sam=ZERO;
    sue=ZERO;

    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited.\n" << "Take $1 from each account.\n" << "Now ";

    sam-=1;
    sue-=1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited.\n" << "Lucky sue!\n";
    


    return 0;
}
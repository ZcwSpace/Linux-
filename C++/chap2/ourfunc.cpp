#include <iostream>

using namespace std;

void simon(int);

int main()
{
    simon(3);
    cout << "Pick an intrger: ";

    int count;

    cin >> count;
    simon(count);
    cout << "Done!\n";

    return 0;
}
void simon(int n)
{
    cout << "Simon says touch your toes " << n << " times.\n";
}

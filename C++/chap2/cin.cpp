#include <iostream>

using namespace std;

int main()
{
    int carrots;

    cout << "How many carrots do yu have?\n";
    cin >> carrots;
    
    cout << "Here are two more.\n";
    carrots+=2;

    cout << "Now you have " << carrots << " carrots.\n";

    return 0; 
}
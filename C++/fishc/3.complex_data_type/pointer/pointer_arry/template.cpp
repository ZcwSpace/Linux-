#include <iostream>

using namespace std;

//泛型程序设计
template <typename elemType>
void print(elemType *pBegin, elemType *pEnd)
{
    while(pBegin !=pEnd)
    {
        cout << *pBegin;
        pBegin++;
    }
}

int main()
{
    int a[5]={0,1,2,3,4};
    
    print(a,a+5);
    cout << endl;
    
    return 0;
}


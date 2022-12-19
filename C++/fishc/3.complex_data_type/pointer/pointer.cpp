//如果想访问指针变量存储的地址所在处的值，则需要对指针变量进行解引用，即在指针变量名的前面加上一个‘*’。
#include <iostream>

int main()
{
    using namespace std;

    int num=6;
    int *num_addr=&num;

    cout << num << endl;
    cout << *num_addr << endl;

    *num_addr=5;

    cout << num << endl;
    cout << *num_addr << endl;
    
    return 0;
}
//void *vPointer;
//注意：对一个无类型指针进行解引用前，必须先把它转换为一种适当的数据类型，不然不知道针变量存储的地址所在处的值所占内存的大小。
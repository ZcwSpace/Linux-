#include <iostream>

int main()
{
    int sum = 0, value = 0;

    while(std::cin >> value)//字母可以结束输入，用Ctrl+D也可以输入文件结束符
    {
        sum+=value;
    }
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
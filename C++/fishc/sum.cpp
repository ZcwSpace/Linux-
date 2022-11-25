/*
要求：编写一个程序，要求用户输入一串整数和任意数目的空格，这些整数必须位于同一行中，但允许出现在该行中的任何位置。当
用户按下键盘上的“ Enter ”键时，数据输入结束。程序自动对所有的整数进行求和并打印出结果。
*/
#include <iostream>

int main()
{
    using namespace std;

    char letter;
    long long sum = 0, temp = 0;

    cout << "请输入一串整数和任意数目的空格：";

    while((letter = getchar()) != '\n')
    {
        temp = 0;
        while(' ' != letter)
        {
            temp = temp * 10 + (letter - 48);
            
            if('\n' == (letter=getchar()))
            {
                goto label;
            }
        }
        sum += temp;
    }
    
label:
    cout << "sum = " << sum << endl;

    return 0;
}
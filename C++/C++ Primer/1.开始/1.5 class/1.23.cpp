#include <stdio.h>
#include "Sales_item.h"

int main()
{
    Sales_item item,temp;
    int count=0;

    std::cin >> item;
    count=1;

    while(std::cin >> temp)
    {
        if(temp.isbn() == item.isbn())
        {
            count++;
        }
        else
        {
            std::cout << item.isbn() << "有" << count << "条销售记录\n";
            item=temp;
            count=1;
        }
    }
    std::cout << item.isbn() << "有" << count << "条销售记录\n";

    return 0;
}
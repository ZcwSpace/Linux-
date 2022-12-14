//problem 2:编写一个温度转换程序，提示用户以【xx.x C】或【xx.x F】的格式输入
#include <iostream>

int main()
{
    using namespace std;
    
    float temperature;
    char type;

    cout << "请输入温度：（格式为：【xx.x C】或【xx.x F】）\n";

    cin >> temperature;
    cin >> type;
    //对输入的温度进行检查，温度不会太高，也不会太低

    switch(type)
    {
        case 'C':
        case 'c':
            temperature=temperature*1.8+32;
            cout << temperature << " F\n"; 
            break;
        case 'F':
        case 'f':
            temperature=(temperature-32)/1.8;
            cout << temperature << " C\n";
            break;
        default:
            cout << "温度的类型输入错误，请输入华氏度(F)或者摄氏度(C)\n";
   }
   //不要相信任何程序的输入，尤其是由用户输入的东西。
   //往好处说：非法输入会让程序变得毫无用处；
   //往坏处说：非法输入会让程序甚至是整个系统崩溃。


   //对输入数据进行合法性检查的具体做法取决于具体的变量类型和它们的取值范围。
   //例如：检查一个数是不是正数。 商品的价格
   //检查某个数值是不是落在给定的范围内。 女朋友的年龄
   //检查某个字符是不是一个特定的值  y或者n
   //cin调用失败

   /*
   cin.eof();//如果到达文件末尾，返回true。
   cin.fail();//如果cin无法互作，返回true。
   cin.bad();//如果cin因为比较严重的原因（例如内存不足）而无法操作，返回true。
   cin.good();//如果以上情况都没发生，返回true。
   */

    cout << "输入任何字符结束程序···";
    cin.ignore(1,'\n');
    cin.get();//从输入队列取一个字符

    return 0;
}
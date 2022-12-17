//problem 1:向用户提出一个问题，用户恢复Y/N，然后把用户输入的值赋值给answer变量

#include <iostream>

int main()
{
    using namespace std;

    char answer;

    cout << "你是男性吗？(回答为：Y/N)\n";  
    /*1
    if('Y'==cin.peek()||'y'==cin.peek())
    {
        cin >> answer;
    }
    else if('N'==cin.peek()||'n'==cin.peek())
    {
        cin >> answer;
    }
    else
    {
        cout << "输入错误！！！\n";

        return 0;
    }
    cout << answer << endl;
    */
   //2
   cin >> answer;

   switch(answer)
   {
    case 'Y':
    case 'y':
        cout << "您的输入为" << answer << endl;
        break;
    case 'N':
    case 'n':
        cout << "您的输入为" << answer << endl;
        break;
    default:
        cout << "输入错误！！！\n";
   }
   //以上程序独自在终端中运行会一闪而过。
   cout << "输入任何字符结束程序···";
   cin.ignore(1,'\n');
   cin.get();//从输入队列取一个字符
   
   return 0;
}






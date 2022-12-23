//结构是对象的基础。
#include <iostream>
#include <fstream>

using namespace std;

struct Person
{
    string name;
    string ID;
    char sex;
}person;

void reading_file();
void writing_file(struct Person person);

int main()
{
    int option;

    while(1)
    {
        cout << "请选择需要进行的操作：\n";
        cout << "1.打印数据到屏幕\n";
        cout << "2.录入数据\n";
        cout << "3.退出程序\n";
        cin >> option;
        cout << endl; 
        if(1==option)
        {
            reading_file();
        }
        else if(2==option)
        {
            cout << "请输入姓名：";
            cin >> person.name;
            cout << "请输入身份证号：";
            cin >> person.ID;
            cout << "请输入性别：";
            cin >> person.sex;
            cout << endl;
            writing_file(person);
        }
        else if(3==option)
        {
            break;
        }
    }

    return 0;
}

void reading_file()
{
    fstream fp("./test.txt",ios::in);
    printf("%-8s\t","姓名");
    printf("%-8s\t","身份证号");
    printf("%-8s\n","性别");
    
    string str;
    while(getline(fp,str))
    {
        cout << str << endl;
    }
    cout << endl;
    fp.close();
}
void writing_file(struct Person person)
{
    fstream fp("./test.txt",ios::out|ios::app);

    fp.seekp(ios::end);
    fp << person.name;
    fp << '\t';
    fp << person.ID;
    fp << '\t';
    fp << person.sex;
    fp << '\n';

    fp.close();
}
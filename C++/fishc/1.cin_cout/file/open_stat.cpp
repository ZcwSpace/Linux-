#include <fstream>//文件流
#include <iostream>

using namespace std;

int main()
{
    
    //ofstream out("test.txt",ios::app);
    fstream fp("test.txt",ios::in|ios::out);
    /*
    ifstream in("test.txt")；//使用了构造函数。构造函数就是对象默认使用的方法
    ofstream out("test1.txt")；
    ifstream in(文件名，打开方式)
    ios::in：打开一个可读取文件
    ios::ous：打开一个可写入文件
    ios::binary：以二进制的方式打开一个文件
    ios::app:写入的所有数据将被追加到文件的末尾
    ios::trunk:删除文件原来已存在的内容
    ios::novreate:如果要打开的文件不存在，那么以此参数调用open函数将无法进行
    ios::noreplace:如果要打开的文件已存在，那么以此参数调用open函数将返回一个错误
    */

    if(!fp)
    {
        cerr << "打开文件失败" << endl;
        return 0;
    }

    fp << "IloveFishc.com!";

    static char str[100];

    fp.seekp(ios::beg);//使得文件指针指向文件头ios::end：文件尾部
    fp >> str;

    cout << str << endl;

    fp.close();

    return 0;
}
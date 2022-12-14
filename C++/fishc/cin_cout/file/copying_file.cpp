#include <fstream>//文件流
#include <iostream>

using namespace std;

int main(char* argv[],int argc)
{
    
    ifstream in;//input file stream
    ofstream out;//out file stream
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

    in.open("test.txt");
    if(!in)
    {
        cerr << "打开文件失败" << endl;
        return 0;
    }

    out.open("test1.txt");
    if(!out)
    {
        cerr << "打开文件失败" << endl;
        return 0;
    }
    
    char x;
    while(in >> x)
    {
        out << x;
    } 
    out << endl;
    in.close();
    out.close();

    printf("成功复制一个文件！\n");

    return 0;
}
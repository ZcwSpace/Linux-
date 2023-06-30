//入口方法
/*
main() {
  print('你好 dart');
}
*/
/*
void main() {
  print('你好 dart');
}
*/

//变量
import 'dart:ffi';

void main() {
  //var：可以自动推断类型
  var str = '你好dart';
  var myNum = 1234;

  print(str);
  print(myNum);

  //字符串
  String str1 = '1230';
  //整形
  int myNum1 = 124;

  //常量
  //const：必须有初始值
  const int age = 45;
  //age = 55;

  //final 可以没有初始值
  final int age2;
  age2 = 5;
  //age2 = 10;

  //final time = new DateTime.now(); //第一次使用时才初始化
  //const time = new DateTime.now(); //报错
  print(time);
}

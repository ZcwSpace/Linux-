import 'dart:ffi';

main() {
  //定义字符串类型的几种方式
  var str1 = 'this is str';
  var str2 = 'this is str';

  print(str1);
  print(str2);

  String str3 = 'this is str';
  String str4 = 'this is str';

  print(str3);
  print(str4);

  String str5 = '''
this is str1

this is str2
''';
  print(str5);

  //字符串的拼接
  String str6 = 'hello';
  String str7 = 'girl';

  print("$str6 $str7");
  print(str6 + ' ' + str7);

  //数值类型
  //int
  int a = 123;
  //double
  double b = 3.15;
  b = 24;

  //数值型运算符
  double c = a + b;

  //bool
  bool flag = true;
  //bool flag = 0;

  //条件判断
  if (flag) {
    print("true");
  } else {
    print('false');
  }

  //list：union,array
  var l1 = [15, 15, '12'];
  print(l1.length);
  //l1.length = 0;
  print(l1.length);
  //print(l1[0]);
  l1[0] = 'af';

  //指定类型
  var l2 = <String>["张三"];

  //增加数据
  var l3 = [];

  l3.add('张三');
  l3.insert(0, 5);
  print(l3);

  //老版本可以使用
  //var l4 = new List();//error

  //固定长度的集合
  var l5 = List.filled(5, 0);
  var l6 = List<int>.filled(5, 0);

  //maps
  //第一种
  var person = {"name": "张三", "age": "46"};

  print(person['name']);

  //第二种
  var p = new Map();

  p["name"] = "李四";

  //用is判断类型
  var str = 1234;
  if (str is int) {
    print('str is string');
  }
}

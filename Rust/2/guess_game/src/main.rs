use std::io;//输入输出函数要用到的库
//io在标准库std里面
//默认情况下rust会把prelude（序曲）库导入到每个程序的作用域中。

//rust中的包分两种，一种是二进制crate，可以运行；另一种是library crate，比如rand，为其它程序所用。
use rand::Rng;//Rng是一个trait（接口）
use std::cmp::Ordering;

fn main() {
    println!("猜数!");

    let secret_num = rand::thread_rng().gen_range(0, 101);
        
    loop 
    {
        println!("猜测一个数：");
    
    //let用来声明变量
    let foo = 1;
    let _bar = foo;

    //默认情况下let声明的变量的值是不可变的。
    //foo = 2;报错

    //如果想要定义的变量是可变的，就需要声明时加上mut
    //String::new()会返回一个字符串的新的实例，也是标准库提供的内部使用的是utf-8格式的编码，并且可以按照需求扩展自己的大小。
        //::：表明new是String类的一个关联函数，针对整个字符串类本身实现，而不是针对字符串的某个特定实例来实现。
    let mut guess = String::new();

    //stdin的返回值为Stdin，
    //&表示引用
    //在rust里，引用默认也是不可变的。所以需要加入mut使得引用变成可变的
    //read_line的返回值Result是一个枚举类型，它有两个两个变体：OK和Err。
    //Result还定义了一些方法，expect就是其中一种
    //expect：如果返回值是Err，就打印参数中的信息；如果是OK，就会提取OK中的值，并将这个值返回给用户。
    io::stdin().read_line(&mut guess).expect("无法读取行");

    //{}是一个占位符。
    println!("你猜测的数是：{}", guess);

    //match相当于if
    //rust允许使用同名的新变量来隐藏旧变量
    //trim：去除两侧的空格和换行
    //
    let guess:u32 = match   guess.trim().parse(){
        Ok(num) => num,
        Err(_) => continue,
    };
        match guess.cmp(&secret_num)
        {
            Ordering::Less => println!("小了"),
            Ordering::Greater => println!("大了"),
            Ordering::Equal => 
            {
                println!("猜对了");
                break;
            },
        }
    }
    

}

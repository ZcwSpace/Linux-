#include<stdio.h>
#include<stdlib.h>

union data
{
    int num;
    char str;
};

void print(int num);
void print1(int *num);

int main(void)
{
    union data data1;
    
    data1.num=5;

    //printf("%d\n",data1);//5
    //printf("%d\n",data1.num);//5

    //print(data1);//报错 "union data" 类型的实参与 "int" 类型的形参不兼容
    //print(data1.num);
    
    print1(&data1);//虽然警告，但可以打印数据
    //print1(&data1.num);
}
void print(int num)
{
    printf("%d\n",num);
}
void print1(int *num)
{
    printf("%d\n",*num);
}
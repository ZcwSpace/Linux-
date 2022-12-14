#include <stdio.h>

void swap(int * a_addr,int *b_addr);

int main()
{
    int a=5,b=6;
    int *a_addr,*b_addr;

    a_addr=&a;
    b_addr=&b;//a_addr:a的地址,b_addr:b的地址;
    //指针变量：存放地址的变量。int变量：存放int型数据的变量。

    printf("%d,%d\n",a,b);

    swap(a_addr,b_addr);
    printf("%d,%d\n",*a_addr,*b_addr);
    printf("%d,%d\n",a,b);

    return 0;
}
/*
void swap(int * a_addr,int *b_addr)//a_addr:a的地址,b_addr:b的地址;
{
    int *p;

    p=a_addr;
    a_addr=b_addr;
    b_addr=p;//a_addr与b_addr里面存放的值（地址）改变了。
}
*/
/*
void swap(int * a_addr,int *b_addr)//a_addr:a的地址,b_addr:b的地址;
{
    int temp;

    temp=*a_addr;
    *a_addr=*b_addr;
    *b_addr=temp;//a_addr与b_addr里面存放的值（地址）改变了。
}
*/
void swap(int * a_addr,int *b_addr)//a_addr:a的地址,b_addr:b的地址;
{
    int *temp;

   *temp=*a_addr;//a_addr:a;temp:没有存放地址。
}

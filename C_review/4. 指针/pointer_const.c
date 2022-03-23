#include <stdio.h>

int main(void)
{
    /*
    int num=2;
    const int *p=&num;//被const修饰符修饰的指针
    *p=1024;//当指针被const修饰符修饰时，p所指向的地址存储的值不可被修改
    */

   /*
    const int num=5;
    const int *p=&num;//指向常量的指针：指针要想指向常量，指针也必须被const修饰符修饰。
    *p=1024;//因为p被const修饰符修饰，所以p所指向的地址存储的值不可被修改
    */

   /*
    int num=2;
    int *const p=&num;//指向变量的常量指针
    p=NULL;//常量指针指向的地址不可被修改
    */

    /*
    const int num=5;//指针要想指向常量，指针也必须被常量修饰。
    const int *const p=&num;//指向常量的常量指针
    */

    


    //printf("*p:%d\n",*p);

    return 0;
}
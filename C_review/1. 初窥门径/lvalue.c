#include<stdio.h>

int main(void)
{
    int a=5;
    ++(a++);
    /*
    lvalue.c: In function ‘main’:
    lvalue.c:6:5: error: lvalue required as increment operand
     ++(a++);
     ^~
     ++(a++)==++(5),a=a+1;
     lvalue(locator value):特定位置的值;
     rvalue(value of an expressio):表达式的值。
    */

    return 0;
}
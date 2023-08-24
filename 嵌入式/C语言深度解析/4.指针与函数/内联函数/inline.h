#ifndef H_A_H
#define H_A_H

static inline int my_max(int a, int b) //inline只有修饰函数定义时才有效
{
    a *= 2;
    b /= 3;
    return (a>b) ? a : b;  //找出最大值
}

#endif
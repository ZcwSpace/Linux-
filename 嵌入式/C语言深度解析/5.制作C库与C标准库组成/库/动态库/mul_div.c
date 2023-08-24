//乘法、除法、平方
#include "calculate.h"

double power(double arg)
{
    double sum = 0;

    sum = mul(arg, arg);

    return sum;
}

double mul(double arg1, double arg2)
{
    double sum = 0;

    sum = arg1 * arg2;

    return sum;
}

double div(double arg1, double arg2)
{
    double sum = 0;

    sum = arg1 / arg2;

    return sum;
}
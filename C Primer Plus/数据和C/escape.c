#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>

int main(void)
{
    float salary;

    printf("\aEnter your desired monthly salary");//\a:warn
    printf("$_______\b\b\b\b\b\b\b");//\b:退格
    scanf("%f",&salary);
    printf("\n\t$%.2f a month is $%.2f a year.",salary,
    salary*12.0);//
    printf("\rGee\n");//\r:回车到行首
    
    return 0;
}